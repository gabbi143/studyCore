#include <iostream>
#include "functionDeclarations.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <limits>


using namespace std;


void title() {
    cout << "                       _______ _______ __   __ ______  __   __ _______ _______ ______   _______ \n";
    cout << "                       |       |       |  | |  |      ||  | |  |       |       |    _ | |       |\n";
    cout << "                       |  _____|_     _|  | |  |  _    |  |_|  |       |   _   |   | || |    ___|\n";
    cout << "                       | |_____  |   | |  |_|  | | |   |       |      _|  | |  |   |_||_|   |___ \n";
    cout << "                       |_____  | |   | |       | |_|   |_     _|     | |  |_|  |    __  |    ___|\n";
    cout << "                        _____| | |   | |       |       | |   | |     |_|       |   |  | |   |___ \n";
    cout << "                       |_______| |___| |_______|______|  |___| |_______|_______|___|  |_|_______|\n\n";
}

void desc(){
    cout << "                          Welcome to studyCore! Where we create a comprehensive environment " << endl;
    cout << "                                  encompassing aspects of student life and study tools." << endl << endl;
}

void VirtualPet::mainMenu() {
    cout << "sCore Points: " << points;
}

bool isValidPassword(const string& password) {
    if (password.length() < 8) {
        cout << endl << "-> Password must be at least:\n   - 8 characters long\n   - Include at least one number\n   - Include a special character." << endl << endl;
        return false;
    }

    bool hasNumber = false, hasSpecialChar = false;
    string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";

    for (char c : password) {
        if (isdigit(c)) hasNumber = true;
        if (specialChars.find(c) != string::npos) hasSpecialChar = true;
    }

    if (!hasNumber) {
        cout << endl << "-> Password must include at least one number." << endl << endl;
        return false;
    }
    if (!hasSpecialChar) {
        cout << endl << "-> Password must include at least one special character. (Ex. &, *, %, $, #)" << endl << endl;
        return false;
    }

    return true;
}

void saveSession(const string& username) {
    ofstream sessionFile("session.txt");
    sessionFile << username;
    sessionFile.close();
}

bool isUserLoggedIn(string& username) {
    ifstream sessionFile("session.txt");
    if (sessionFile.is_open()) {
        getline(sessionFile, username);
        sessionFile.close();
        return !username.empty();
    }
    return false;
}


void logout() {
    ofstream sessionFile("session.txt", ios::trunc);
    sessionFile.close();
    system("cls");

    cout << endl << "                                            You have logged out successfully." << endl;
    string choice;
    while (true) {
        title();
        desc();
        cout << "     1. Sign Up\n     2. Log In\n\n     - Choice: ";
        getline(cin, choice);


        if (choice == "1") {
            system("cls");

            createAccount();
        } else if (choice == "2") {

            login();

        } else {
            system("cls");
            cout << endl << "-> Invalid choice. Please try again." << endl << endl;
        }
    }

}

void mainMenu() {
    while (true) {

        title();

        cout << endl << endl << "This is the main menu." << endl;
        cout << "1. Logout\n2. Exit\nChoice: ";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            logout();

        } else if (choice == "2") {
            system("cls");
            title();
            cout << endl <<"                                                    Goodbye for now!" << endl << endl;
            exit(0);
        } else {
            system("cls");
            cout << endl <<"                                              Please enter a valid choice." << endl;
        }
    }

}

void createAccount() {
    cout << endl;
    title();
    desc();
    string username, password, verifyPassword;
    int recoveryPIN;

    cout << "                        ___                  _               ___                           _   " << endl;
    cout << "                       / __| _ _  ___  __ _ | |_  ___       /   \\ __  __  ___  _  _  _ _  | |_ " << endl;
    cout << "                      | (__ | '_|/ -_)/ _` ||  _|/ -_)      | - |/ _|/ _|/ _ \\| || || ' \\ |  _|" << endl;
    cout << "                       \\___||_|  \\___|\\__/_| \\__|\\___|      |_|_|\\__|\\__|\\___/ \\_._||_||_| \\__|" << endl;
    cout << endl << endl;

    while (username.empty()) {

    cout << "                    (A 4-figit PIN will be generated upon creating an account to change a password.)" << endl << endl;
        cout << "          - Username: ";
        getline(cin, username);
        if (username.empty()) {
            cout << endl << "Username cannot be empty. Please enter a valid username." << endl << endl;
        }
    }

    while (true) {
        cout << "          - Password: ";
        getline(cin, password);

        if (!isValidPassword(password)) {
            cout << "Please enter a stronger password." << endl << endl;
            continue;
        }

        cout << "          - Verify Password: ";
        getline(cin, verifyPassword);

        if (password == verifyPassword) {
            break;
        } else {
            cout << "Passwords do not match. Please try again." << endl << endl;
        }
    }

    srand(time(0));
    recoveryPIN = rand() % 9000 + 1000;

    // Save credentials to file
    ofstream file("credentials.txt");
    file << username << endl << password << endl << recoveryPIN;
    file.close();
    system("cls");
    cout << endl << "                                       Your account has been created successfully!" << endl;
    cout << "                                                 Your recovery PIN: " << recoveryPIN << endl;
    cout << "                              (Keep this PIN safe, you will need it for password recovery.)" << endl;

    saveSession(username);

    mainMenu();
}

bool verifyLogin(const string& username, const string& password) {
    ifstream file("credentials.txt");
    string storedUser, storedPass;

    if (file.is_open()) {
        getline(file, storedUser);
        getline(file, storedPass);
        file.close();
        return username == storedUser && password == storedPass;
    }
    return false;
}

void login() {
    string username, password;
    int choice, recoveryPIN, enteredPIN;

    system("cls");
    cout << endl;
    title();
    desc();
    cout << "                                               _                _      " << endl;
    cout << "                                              | |   ___  ___   | | _ _ " << endl;
    cout << "                                              | |_ / . \\/ . |  | || ' |" << endl;
    cout << "                                              |___|\\___/\\_. |  |_||_|_|" << endl;
    cout << "                                                        [___|          " << endl;

    while (username.empty()) {
        cout << "          - Username: ";
        getline(cin, username);
        if (username.empty()) {
            cout << endl << "Username cannot be empty. Please enter a valid username." << endl << endl;
        }
    }

    ifstream file("credentials.txt");
    string storedUsername, storedPassword, verifyPassword;

    if (file) {
        getline(file, storedUsername);
        getline(file, storedPassword);
        file >> recoveryPIN;
        file.close();
    }

    while (true) {
        cout << "          - Password: ";
        getline(cin, password);

        if (verifyLogin(username, password)) {
            saveSession(username);
            system("cls");
            cout << endl << "                                             Login successful. Welcome, " << username << "!" << endl;
            mainMenu();
            return;
        } else {
            cout << endl << "- > Invalid username or password." << endl;

            while (true) {
                cout << "     1. Re-enter password" << endl;
                cout << "     2. Forgot password (Reset)" << endl << endl;
                cout << "   Choose an option: ";
                cin >> choice;
                cin.ignore();

                if (choice == 1) {
                        cout << endl ;
                    break;

                } else if (choice == 2) {
                    cout << endl << "          - Enter your 4-digit recovery PIN: ";
                    cin >> enteredPIN;
                    cin.ignore();

                    if (enteredPIN == recoveryPIN) {
                        while (true) {
                            cout << "          - Recovery PIN Verified! Enter a new Password: ";
                            getline(cin, password);

                            if (!isValidPassword(password)) {
                                cout << "Please enter a stronger password." << endl << endl;
                                continue;
                            }

                            cout << "          - Verify Password: ";
                            getline(cin, verifyPassword);

                            if (password == verifyPassword) {
                                break;
                            } else {
                                cout << "Passwords do not match. Please try again." << endl << endl;
                            }
                        }


                        ofstream outFile("credentials.txt");
                        outFile << username << endl << password << endl << recoveryPIN;
                        outFile.close();
                        system("cls");
                        cout << "                                   Your password has been successfully changed!" << endl;
                        return;

                    } else {
                        system("cls");
                        cout << "                              Incorrect recovery PIN or username. Password reset failed." << endl;
                        string choice;
                        while (true) {
                            cout << endl;
                            title();
                            desc();
                            cout << "     1. Sign Up\n     2. Log In\n\n     - Choice: ";
                            getline(cin, choice);

                            if (choice == "1") {
                                system("cls");

                                createAccount();
                            } else if (choice == "2") {

                                login();

                            } else {
                                system("cls");
                                cout << endl << "-> Invalid choice. Please try again." << endl << endl;
                            }
                        }
                    }
                } else {
                    cout << "Invalid option. Please enter 1 or 2." << endl;
                }
            }
        }
    }
}
