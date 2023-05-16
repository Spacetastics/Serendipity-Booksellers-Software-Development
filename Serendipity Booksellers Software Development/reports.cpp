/*
    File: reports.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays the reports menu screen with 7 options, and allows the user to input a choice.
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <iostream>
#include <iomanip>

//project headers
#include "reports.h"

using namespace std;

//stub function implementations
void repListing() {
    cout << "You selected Inventory Listing." << endl;
}

void repWholesale() {
    cout << "You selected Inventory Wholesale Value." << endl;
}

void repRetail() {
    cout << "You selected Inventory Retail Value." << endl;
}

void repQty() {
    cout << "You selected Listing By Quantity." << endl;
}

void repCost() {
    cout << "You selected Listing By Cost." << endl;
}

void repAge() {
    cout << "You selected Listing By Age." << endl;
}

//main function implementation
int reports() {

    //makes an int variable to store the user's choice
    int choice;
    //continually asks the user to enter a choice until they enter 7 (main menu)
    do {

        //print header
        cout << right << setw(26) << "Serendipity Booksellers" << endl;
        cout << right << setw(18) << "Reports" << endl << endl;

        //print seven options and ask user to input choice
        cout << "1. Inventory Listing" << endl << "2. Inventory Wholesale Value" << endl << "3. Inventory Retail Value" << endl << "4. Listing by Quantity" << endl << "5. Listing by Cost" << endl << "6. Listing by Age" << endl << "7. Return to Main Menu" << endl << endl;

        //asks user for input and stores console input in choice
        cout << "Enter Your Choice: ";
        cin >> choice;

        //basic input validation, does not check whether what was entered is an integer
        while (choice < 1 || choice > 7) {
            cout << endl << "Please enter a number in the range 1-7: ";
            cin >> choice;
        }

        cout << endl; //formatting
        switch (choice) {
            case 1:
                repListing();
                break;
            case 2:
                repWholesale();
                break;
            case 3:
                repRetail();
                break;
            case 4:
                repQty();
                break;
            case 5:
                repCost();
                break;
            case 6:
                repAge();
                break;
            case 7:
                cout << "Returning..." << endl;
                break;
            //this should never be reached
            default:
                cout << "ERROR" << endl;
                break;
        }
        cout << endl; //formatting

    } while (choice != 7);

    return 0;
}
