/*
    File: invmenu.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays the inventory menu screen with four options, and allows the user to input a choice.
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <iostream>
#include <iomanip>
#include <string>

//project headers
#include "invmenu.h"

using namespace std;

//global arrays for book information, may need to move these to a different file later
//data for a book is linked through subscripts
string bookTitle[20];
string isbn[20];
string author[20];
string publisher[20];
string dateAdded[20];
int qtyOnHand[20];
double wholesale[20];
double retail[20];

//stub function implementations
void lookUpBook() {
    cout << "You selected Look Up Book." << endl;
}

void addBook() {
    cout << "You selected Add Book." << endl;
}

void editBook() {
    cout << "You selected Edit Book." << endl;
}

void deleteBook() {
    cout << "You selected Delete Book." << endl;
}

//main function implementation
int invMenu() {

    //makes an int variable to store the user's choice
    int choice;
    //continually asks the user to enter a choice until they enter 5 (return to main menu)
    do {

        //print header
        cout << right << setw(26) << "Serendipity Booksellers" << endl;
        cout << right << setw(23.5) << "Inventory Database" << endl << endl;

        //print five options
        cout << "1. Look Up a Book" << endl << "2. Add a Book" << endl << "3. Edit a Book's Record" << endl << "4. Delete a Book" << endl << "5. Return to the Main Menu" << endl << endl;

        //asks user for input and stores console input in choice
        cout << "Enter Your Choice: ";
        cin >> choice;

        //basic input validation, does not check whether what was entered is an integer
        while (choice < 1 || choice > 5) {
            cout << endl << "Please enter a number in the range 1-5: ";
            cin >> choice;
        }

        cout << endl; //formatting
        switch (choice) {
            case 1:
                lookUpBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                cout << "Returning..." << endl;
                break;
            //this should never be reached
            default:
                cout << "ERROR" << endl;
                break;
        }
        cout << endl; //formatting

    } while (choice != 5);

    return 0;
}
