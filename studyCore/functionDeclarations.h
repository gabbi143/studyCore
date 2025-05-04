#ifndef FUNCTIONDECLARATIONS_H_INCLUDED
#define FUNCTIONDECLARATIONS_H_INCLUDED
#include <fstream>

using namespace std;

class VirtualPet {
    public:
        int points;

    VirtualPet(int p) {
        points = p;
    }

    void score();

};

class Score {
public:
    int points;

    Score() {
        points = loadScore();
    }

    void updateScore(int value) {
        points += value;
        saveScore();
    }

    void saveScore() {
        ofstream file("score.txt");
        file << points;
        file.close();
    }

    int loadScore() {
        ifstream file("score.txt");
        int savedPoints;
        if (file >> savedPoints) {
            file.close();
            return savedPoints;
        }
        return 0;
    }
};
struct FlashCard {
    string question;
    string answer;
};

void title();
void desc();
void updateScoreFile(Score& score);
bool isValidPassword(const string& password);
void saveSession(const string& username);
bool isUserLoggedIn(string& username);
void logout();
void mainMenu(const string& username);
void createAccount();
bool verifyLogin(const string& username, const string& password);
void login();
void saveNotesToFile();
void TakeNotes();
void TaskReminder();
void DigitalDetoxTimer();
void MakeFlashCard(const string& username);
void GradeCalculatorOption();
void GradeCalculator();
void ClearAllData();



void EnterFlashCards();
void ViewFlashCards();
void StudyNow();

;
#endif // FUNCTIONDECLARATIONS_H_INCLUDED
