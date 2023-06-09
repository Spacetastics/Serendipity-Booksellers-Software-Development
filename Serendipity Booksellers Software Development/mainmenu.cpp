/*
    File: mainmenu.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays a main menu screen with four options, and allows the user to input a choice.
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard libray headers
#include <iostream>
#include <iomanip>

//project headers
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"

using namespace std;

//PROJECT MAIN
int main() {
    
    //makes an int variable to store the user's choice
    int choice;
    //continually asks the user to enter a choice until they enter 4 (exit)
    do {

        //print main menu:
        //(formatting) prints three empty spaces to the left of the following string,
        //as the string has a length of 23
        cout << right << setw(26) << "Serendipity Booksellers" << endl;
        //(formatting) prints 10 empty spaces to the left of the following string,
        //as the string has a length of 9
        cout << right << setw(19) << "Main Menu" << endl << endl;
        //prints out the four menu options, one on each line, and then asks the user
        //to enter their choice
        cout << "1. Cashier Module" << endl << "2. Inventory Database Module" << endl << "3. Report Module" << endl << "4. Exit" << endl << endl;

        //asks user for input and stores console input in choice
        cout << "Enter Your Choice: ";
        cin >> choice;

        //basic input validation, does not check whether what was entered is an integer
        while (choice < 1 || choice > 4) {
            cout << endl << "Please enter a number in the range 1-4: ";
            cin >> choice;
        }

        cout << endl; //formatting
        switch (choice) {
            case 1:
                cin.ignore();
                cashier();
                break;
            case 2:
                invMenu();
                break;
            case 3:
                reports();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            //this should never be reached
            default:
                cout << "ERROR" << endl;
                break;
        }

    } while (choice != 4);

    return 0;
    
    //NOTES:
    
    //might get rid of serendipity booksellers title in every menu except the main menu for easy readability
    //might want to abstract certain values in various files into constant variables for readability
}
