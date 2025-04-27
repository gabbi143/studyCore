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
        cout << endl << "-> Password must include at least one special character." << endl << endl;
        return false;
    }

    return true;
}

// Save login session to a file
void saveSession(const string& username) {
    ofstream sessionFile("session.txt");
    sessionFile << username;
    sessionFile.close();
}

// Check if a user is already logged in
bool isUserLoggedIn(string& username) {
    ifstream sessionFile("session.txt");
    if (sessionFile.is_open()) {
        getline(sessionFile, username);
        sessionFile.close();
        return !username.empty();
    }
    return false;
}

// Remove session file to log out the user
void logout() {
    ofstream sessionFile("session.txt", ios::trunc);
    sessionFile.close();
    system("cls");
    cout << "You have logged out successfully." << endl;

}

// Display main menu
void mainMenu() {

    title();

    cout << endl << endl << "This is the main menu." << endl;
    cout << "1. Logout\n2. Exit\nChoice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        logout();
    }
}

// Create a new user account
void createAccount() {
    title();
    desc();
    string username, password, verifyPassword;
        cout << "                        ___                  _               ___                           _   " << endl;
        cout << "                       / __| _ _  ___  __ _ | |_  ___       /   \\ __  __  ___  _  _  _ _  | |_ " << endl;
        cout << "                      | (__ | '_|/ -_)/ _` ||  _|/ -_)      | - |/ _|/ _|/ _ \\| || || ' \\ |  _|" << endl;
        cout << "                       \\___||_|  \\___|\\__/_| \\__|\\___|      |_|_|\\__|\\__|\\___/ \\_._||_||_| \\__|" << endl;
        cout << endl << endl;
    Sleep(500);

    while (username.empty()) {
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

    ofstream file("data\credentials.txt");
    file << username << endl << password;
    file.close();

    saveSession(username); // Save session so user doesn't need to log in again
    system("cls");
    cout << endl << "                                             Account created successfully." << endl;
    mainMenu();
}

// Log in an existing user
bool verifyLogin(const string& username, const string& password) {
    ifstream file("data\credentials.txt");
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

    system("cls");

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
        cout << "          - Password: ";
        getline(cin, password);

        if (verifyLogin(username, password)) {
            saveSession(username);
            system("cls");

            cout << "Login successful." << endl;
            mainMenu();
        } else {
            system("cls");
            cout << "Invalid username or password. Please try again." << endl;


        }
}
