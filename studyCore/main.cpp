#include <iostream>
#include "functionDeclarations.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <limits>

using namespace std;

int main()
{
    VirtualPet pet(0);

    string username;

    // Check if user is already logged in
    if (isUserLoggedIn(username)) {
        cout << "Welcome back, " << username << "!" << endl;
        mainMenu();
        return 0;
    }

    int choice;
    while (true) {
        title();
        desc();
        cout << "     1. Sign Up\n     2. Log In\n\n     - Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            system("cls");

            createAccount();
        } else if (choice == 2) {
            login();
        } else {
            system("cls");
            cout << endl << "-> Invalid choice. Please try again." << endl << endl;
        }
    }


    return 0;
}
