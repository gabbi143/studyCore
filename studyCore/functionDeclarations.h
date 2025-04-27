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

    void mainMenu();
};
void title();
void desc();
bool isValidPassword(const string& password);
void saveSession(const string& username);
bool isUserLoggedIn(string& username);
void logout();
void mainMenu();
void createAccount();
bool verifyLogin(const string& username, const string& password);
void login();
;
#endif // FUNCTIONDECLARATIONS_H_INCLUDED
