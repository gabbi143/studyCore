#ifndef FUNCTIONDECLARATIONS_H_INCLUDED
#define FUNCTIONDECLARATIONS_H_INCLUDED
#include <fstream>


#include<vector>
using namespace std;

struct FlashCard {
    string question;
    string answer;
};

class VirtualPet {
private:
    string name;
    vector<string> pettingResponses;
    vector<string> feedingResponses;
    vector<string> barkingResponses;

public:
    VirtualPet(string petName);
    void introduce();
    void pet();
    void feed();
    void bark();
};

void virtualPetMenu(VirtualPet& byte);

void title();
void desc();

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
