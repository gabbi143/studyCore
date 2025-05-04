#include <iostream>
#include "functionDeclarations.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <limits>
#include <vector>
#include <direct.h>
#include <map>

#include <filesystem> // Ensure you include this



using namespace std;

class VirtualPet;
void mainMenu();

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
void mainMenu(const string& username) {
    while (true) {

            Score score;

        title();

            cout << "                                          _____     _        _____             \n";
            cout << "                                         |     | __|_|___   |     |___ ___ _ _ \n";
            cout << "                                         | | | ||. | |   |  | | | | -_|   | | |\n";
            cout << "                                         |_|_|_|___|_|_|_|  |_|_|_|___|_|_|___|\n\n";

            cout << "           - sCore Points: " << score.points;

            cout << endl << endl;
            cout << "           1. Take Notes \n";
            cout << "           2. Task Reminder \n";
            cout << "           3. Digital Detox Timer \n";
            cout << "           4. Make Flashcard \n";
            cout << "           5. Grade Calculator \n";
            cout << "           6. Clear All Data \n";
            cout << "           7. Log out \n";
            cout << "           8. Exit \n";
            cout << "           9. Add Points \n\n";

            cout << "           - Choice: ";

        string choice;
        getline(cin, choice);

        if (choice == "7") {
            logout();
        } else if (choice == "8") {
            system("cls");
            title();
            cout << endl <<"                                                    Goodbye for now!" << endl << endl;
            exit(0);
        }else if (choice == "1"){
            TakeNotes();
        }else if (choice == "2"){
            system("cls");
            TaskReminder();
        } else if (choice == "3"){
            system("cls");
            DigitalDetoxTimer();
        } else if (choice == "4"){
            system("cls");
            MakeFlashCard(username);
        } else if (choice == "5"){
            system("cls");
            GradeCalculatorOption();
        } else if (choice == "6"){
            system("cls");
            ClearAllData();
        } else if (choice == "9") {
            system("cls");
            score.updateScore(4);
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


    ofstream file("credentials.txt", ios::app);

    file << username << endl << password << endl << recoveryPIN;
        file.close();

        string folderName = "users\\" + username;
        if (_mkdir("users") == 0 || errno == EEXIST) {
        if (_mkdir(folderName.c_str()) == 0) {
                system("cls");
                cout << "                                     User folder '" << folderName << "' created successfully.\n";
                cout << "                                                 Your recovery PIN: " << recoveryPIN << endl;
                cout << "                              (Keep this PIN safe, you will need it for password recovery.)" << endl;

                saveSession(username);
                mainMenu(username);
            } else {
                system("cls");
                title();
                cout << "Failed to create user folder as it has the same folder name to another user.\n";
                Sleep(2000);
                    }
                } else {
                    cout << "Failed to create 'users' root directory.\n";
                    Sleep(2000);
            }
}

bool verifyLogin(const string& username, const string& password) {
    ifstream file("credentials.txt");
    string storedUser, storedPass;
    int storedPIN;

    if (file.is_open()) {
        while (getline(file, storedUser)) {
            getline(file, storedPass);
            file >> storedPIN;
            file.ignore();

            if (username == storedUser && password == storedPass) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void resetPassword(const string& username, int enteredPIN) {
    ifstream file("credentials.txt");
    vector<string> accounts;
    string storedUser, storedPass;
    int storedPIN;
    bool found = false;


    while (getline(file, storedUser)) {
        getline(file, storedPass);
        file >> storedPIN;
        file.ignore();

        if (username == storedUser && enteredPIN == storedPIN) {
            found = true;
            cout << "Enter new password: ";
            string newPassword;
            getline(cin, newPassword);

            while (!isValidPassword(newPassword)) {
                cout << "Please enter a stronger password: ";
                getline(cin, newPassword);
            }

            storedPass = newPassword;
        }

        accounts.push_back(storedUser);
        accounts.push_back(storedPass);
        accounts.push_back(to_string(storedPIN));
    }
    file.close();

    if (!found) {
        cout << "Incorrect username or recovery PIN." << endl;
        return;
    }

    ofstream outFile("credentials.txt", ios::trunc);
    for (const string& line : accounts) {
        outFile << line << endl;
    }
    outFile.close();

    cout << "Password updated successfully!" << endl;
}


void login() {
    string username, password, verifyPassword;
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
    string storedUsername, storedPassword;
    bool accountFound = false;
    vector<pair<string, int>> accountData;

    while (getline(file, storedUsername)) {
        getline(file, storedPassword);
        file >> recoveryPIN;
        file.ignore();

        accountData.push_back({storedUsername, recoveryPIN});

        if (storedUsername == username) {
            accountFound = true;
            break;
        }
    }
    file.close();

    if (!accountFound) {
        system("cls");
        cout << endl << "- > Username not found. Please try again or sign up." << endl;
        return;
    }

    while (true) {
        cout << "          - Password: ";
        getline(cin, password);

        if (verifyLogin(username, password)) {
            saveSession(username);
            system("cls");
            cout << endl << "                                             Login successful. Welcome, " << username << "!" << endl;
            mainMenu(username);
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
                    cout << endl;
                    break;
                } else if (choice == 2) {
                    cout << endl << "          - Enter your 4-digit recovery PIN: ";
                    cin >> enteredPIN;
                    cin.ignore();


                    for (const auto& account : accountData) {
                        if (account.first == username && account.second == enteredPIN) {
                            cout << "          - Recovery PIN Verified! Enter a new Password: ";
                            while (true) {
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
                            for (const auto& account : accountData) {
                                if (account.first == username) {
                                    outFile << username << endl << password << endl << enteredPIN << endl;
                                } else {
                                    outFile << account.first << endl << storedPassword << endl << account.second << endl;
                                }
                            }
                            outFile.close();

                            system("cls");
                            cout << "                                      Your password has been successfully changed!" << endl;
                            mainMenu(username);
                            return;
                        }
                    }

                    system("cls");
                    cout << "                              Incorrect recovery PIN or username. Password reset failed." << endl;
                    return;
                } else {
                    cout << "Invalid option. Please enter 1 or 2." << endl;
                }
            }
        }
    }
}

vector<string> notes;

void saveNotesToFile(const vector<string>& notes, const string& username) {
    string filename = "users/" + username + "/notes.txt";
    ofstream outFile(filename);
    for (const string& note : notes) {
        outFile << note << endl;
    }
}

void loadNotesFromFile(vector<string>& notes, const string& username) {
    string filename = "users/" + username + "/notes.txt";
    ifstream inFile(filename);
    string note;
    notes.clear();
    while (getline(inFile, note)) {
        if (!note.empty()) {
            notes.push_back(note);
        }
    }
}

void TakeNotes() {
    string username;
    if (!isUserLoggedIn(username)) {
        cout << "You must be logged in to use this feature." << endl;
        return;
    }

    loadNotesFromFile(notes, username);

    int choice;
    int ViewChoice;
    int delIndex;

    while (true) {
        system("cls");
        title();
        cout << "                         ___________       __            ______ |\\         __                 \n";
        cout << "                         \\__    ___/____  |  | __ ____   \\     \\| | ____ _/  |_  ____   ______\n";
        cout << "                            |    |  \\__  \\ |  |/ // __ \\  /   |    |/ __ \\\\   __\\/ __ \\ /  ___/\n";
        cout << "                            |    |   / __ \\_    \\\\  ___/_/    |\\   |  \\_\\ )|  | \\  ___/_\\___ \\ \n";
        cout << "                            |____|  (____  /__|_ \\\\___  /\\____| \\  /\\____/ |__|  \\___  /____  \\\n";
        cout << "                                         \\/     \\/    \\/         \\/                  \\/     \\/ \n\n";

        cout << "                       1. Create New Note\n";
        cout << "                       2. View Notes\n";
        cout << "                       3. Go back\n\n";

        cout << "                       - Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string note;
            system("cls");
            title();
            cout << "Enter your note: ";
            getline(cin, note);
            notes.push_back(note);
            saveNotesToFile(notes, username);
            cout << "\n\n Note saved!\n";
            Sleep(1000);
        } else if (choice == 2) {
            if (notes.empty()) {
                system("cls");
                title();
                cout << "                                                ============================= \n";
                cout << "                                                     No notes saved yet. \n";
                cout << "                                                ============================= \n";
                Sleep(1500);
            } else {
                system("cls");
                title();
                cout << "                                                =========================== \n";
                cout << "                                                        Your Notes \n";
                cout << "                                                --------------------------- \n";
                for (int i = 0; i < notes.size(); ++i) {
                    cout << "" << i + 1 << ". " << notes[i] << "\n";
                }
                cout << "\n                                                =========================== \n";
                cout << "\n                1. Delete Note \n";
                cout << "                  2. Go Back \n\n";

                cout << "\n                - Enter your Choice: ";
                cin >> ViewChoice;
                cin.ignore();

                if (ViewChoice == 1) {
                    cout << "Enter the note number to delete: ";
                    cin >> delIndex;
                    cin.ignore();
                    if (delIndex > 0 && delIndex <= notes.size()) {
                        notes.erase(notes.begin() + delIndex - 1);
                        saveNotesToFile(notes, username);
                        cout << "Note deleted successfully.\n\n";
                        Sleep(1000);
                    } else {
                        cout << "Invalid note number.\n\n";
                        Sleep(1000);
                    }
                }
            }
        } else if (choice == 3) {
            system("cls");
            return;
        } else {
            cout << "Invalid choice. Try again.\n";
            Sleep(1000);
        }
    }
}

void TaskReminder() {
    title();
    cout << "\n schedule Reminder deature coming soon...\n";
    Sleep(1500);
    system("cls");
}
void DigitalDetoxTimer() {
    title();
    cout << "\n Digital Detox Timer feature coming soon...\n";
    Sleep(1500);
    system("cls");
}


map<string, vector<FlashCard>> flashcards;



void saveFlashCardsToFile(const map<string, vector<FlashCard>>& flashcards, const string& username) {
    string filename = "users/" + username + "/flashcards.txt";
    ofstream outFile(filename);

    for (const auto& [topic, cards] : flashcards) {
        outFile << "Topic: " << topic << endl;
        for (const auto& card : cards) {
            outFile << "Q: " << card.question << endl;
            outFile << "A: " << card.answer << endl;
        }
        outFile << "---" << endl; // Separator between topics
    }
}


void loadFlashCardsFromFile(const string& username) {
    string filename = "users/" + username + "/flashcards.txt";
    ifstream inFile(filename);

    string line, topic, question, answer;
    flashcards.clear();

    while (getline(inFile, line)) {
        if (line.find("Topic: ") == 0) {
            topic = line.substr(7);
        } else if (line.find("Q: ") == 0) {
            question = line.substr(3);
        } else if (line.find("A: ") == 0) {
            answer = line.substr(3);
            flashcards[topic].push_back({question, answer});
        }
    }
}

void EnterFlashCards() {
    string topic, question, answer;
    system("cls");
    cout << "- Enter a topic: ";
    getline(cin, topic);

    while (true) {
        cout << "\n     => Q. Enter question (or type 'done' to finish): ";
        getline(cin, question);
        if (question == "done") {
            system("cls");
            break;
        }

        cout << "\n     -> A. Enter answer: ";
        getline(cin, answer);

        flashcards[topic].push_back({question, answer});
        cout << "         ------------" << endl;
    }
}

void ViewFlashCards() {
    system("cls");
    cout << "Flashcards:\n\n";

    if (flashcards.empty()) {
        cout << "No flashcards available.\n\n";
        system("pause");
        return;
    }

    for (const auto& [topic, cards] : flashcards) {
        cout << "Topic: " << topic << "\n";
        for (size_t i = 0; i < cards.size(); i++) {
            cout << i + 1 << ". Q: " << cards[i].question << "\n";
            cout << "   A: " << cards[i].answer << "\n\n";
        }
    }

    cout << "Would you like to delete a flashcard? (y/n): ";
    string choice;
    getline(cin, choice);

    if (choice == "y" || choice == "Y") {
        cout << "Enter the topic of the flashcard to delete: ";
        string topic;
        getline(cin, topic);

        if (flashcards.find(topic) == flashcards.end()) {
            cout << "Topic not found.\n";
            system("pause");
            return;
        }

        cout << "Enter the number of the question to delete: ";
        int num;
        cin >> num;
        cin.ignore();

        if (num < 1 || num > flashcards[topic].size()) {
            cout << "Invalid choice.\n";
        } else {
            flashcards[topic].erase(flashcards[topic].begin() + (num - 1));
            cout << "Flashcard deleted successfully.\n";

            if (flashcards[topic].empty()) {
                flashcards.erase(topic);
            }
        }
    }

    system("pause");
    system("cls");
}

void StudyNow() {
    system("cls");
    int correctCount = 0, totalCount = 0;

    for (const auto& [topic, cards] : flashcards) {
        for (const auto& card : cards) {
            totalCount++;
            cout << "QUESTION #" << totalCount << "\n\n";
            cout << "     Question: " << card.question << "\n\n";
            cout << "     1. Reveal Answer\n";
            cout << "- Choice: ";

            string choice;
            getline(cin, choice);
            if (choice == "1") {
                cout << "\n     Answer: " << card.answer << "\n\n";
                cout << "How well do you know this?\n";
                cout << "  5 - Expert\n  4 - Proficient\n  3 - Familiar\n  2 - Emerging\n  1 - Novice\n\n";
                cout << "- Your Answer: ";

                int rating;
                cin >> rating;
                cin.ignore();

                if (rating >= 4) correctCount++;

                cout << "\n-------------------------------------------\n";
            }
        }
    }

    float accuracy = (totalCount == 0) ? 0 : (correctCount * 100.0 / totalCount);
    cout << "\nYour Study Accuracy: " << accuracy << "%\n";
    system("pause");
    system("cls");
}

void MakeFlashCard(const string& username) {
    loadFlashCardsFromFile(username);

    string choice;
    while (true) {
        system("cls");
        title();

        cout << "                                ____  _      __    __   _     __    __    ___   ___   __ \n";
        cout << "                               | |_  | |    / /\\  ( (` | |_| / /`  / /\\  | |_) | | \\ ( (`\n";
        cout << "                               |_|   |_|__ /_/--\\ _)_) |_| | \\_\\_ /_/--\\ |_| \\ |_|_/ _)_)\n";

        cout << "     1. Enter Flashcard/s\n";
        cout << "     2. View Flashcard/s\n";
        cout << "     3. Study Now\n";
        cout << "     4. Go Back\n\n";
        cout << "     - Choice: ";
        getline(cin, choice);

        if (choice == "1") EnterFlashCards();
        else if (choice == "2") ViewFlashCards();
        else if (choice == "3") StudyNow();
        else if (choice == "4") {
            saveFlashCardsToFile(flashcards, username);

            system("cls");
            break;
        }
    }
}


void GradeCalculatorOption(){
    int CalOption;
    system("cls");
    title();
        cout << "                             _____           _        _____     _         _     _           \n";
        cout << "                            |   __|___  __ _| |___   |     | __| |___ _ _| | __| |_ ___ ___ \n";
        cout << "                            |  |  |  _||. | . | -_|  |   --||. | |  _| | | ||. |  _| . |  _|\n";
        cout << "                            |_____|_| |___|___|___|  |_____|___|_|___|___|_|___| | |___|_|  \n";
        cout << "                                                                               |__|        \n\n";

    cout << "               1. Calculate \n";
    cout << "               2. Go Back \n";
    cout << endl << endl;
    cout << "               - Enter Choice: ";
    cin >> CalOption;
        if (CalOption == 1){
            system("cls");
            GradeCalculator();
        } else if (CalOption == 2){
            return;
        } else {
            return;
        }
}

void GradeCalculator() {
    system("cls");

    while (true) {
        int numSubjects;
        float sum = 0.0;
        double average;
        string grade;
        char continueChoice;

        title();
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        if (numSubjects <= 0) {
            cout << "Number of subjects must be greater than 0." << endl;
            Sleep(2000);
            GradeCalculatorOption();
        } else if (numSubjects >= 11) {
            cout << "Maximum number of subjects is 10." << endl;
            Sleep (2000);
            GradeCalculatorOption();

        }

        for (int i = 1; i <= numSubjects; ++i) {
            float marks;
            cout << "Enter marks for subject " << i << ": ";
            cin >> marks;

            if (marks < 65 || marks > 100) {
                cout << "Invalid input. Marks must be between 65 and 100." << endl;
                GradeCalculatorOption();
            }

            sum += marks;
        }

        average = sum / numSubjects;

        cout << "Your average score is: " << average << endl;

        if (average >= 96.4) {
            grade = "1.0";
        }
        else if (average >= 93.1) {
            grade = "1.25";
        }
        else if (average >= 89.8) {
            grade = "1.50";
        }
        else if (average >= 86.5) {
            grade = "1.75";
        }
        else if (average >= 83.2) {
            grade = "2.00";
        }
        else if (average >= 79.9) {
            grade = "2.25";
        }
        else if (average >= 76.6) {
            grade = "2.50";
        }
        else if (average >= 73.3) {
            grade = "2.75";
        }
        else if (average >= 70) {
            grade = "3.00";
        }
        else {
            grade = "5.00";
        }

        cout << "Your General Average is: " << grade << endl;
        cout << "Do you want to calculate grades again? (y/n): ";
        cin >> continueChoice;

        if (continueChoice == 'y' || continueChoice == 'Y') {
            system("cls");
            GradeCalculator();
        } else if (continueChoice == 'n' || continueChoice == 'N'){
            system("cls");
            GradeCalculatorOption();
        }
    }
}

void ClearAllData() {
    title();
    cout << "\n Clear All Data feature coming soon...\n";
    Sleep(1500);
    system("cls");
}



