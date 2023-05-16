/*
    File: cashier.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Asks the user for the information for one book, and then displays the sale slip with that information
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <iostream>
#include <iomanip>
#include <string>

//project headers
#include "cashier.h"

using namespace std;

//main function implementation
int cashier() {
    //no input validation at the moment
    
    //makes an int variable to store a users choice
    int choice;
    do {
        
        //print out header
        cout << right << setw(26) << "Serendipity Booksellers" << endl;
        cout << right << setw(21.5) << "Cashier Module" << endl << endl;

        //get sales data:

        //get sale date
        cout << "Date: ";
        string date;
        getline(cin, date);

        //get number of this book purchased
        cout << "Quantity of Book: ";
        int quantity;
        cin >> quantity;
        cin.ignore(); //ignore remaining '\n' char stored in buffer

        //get book ISBN
        cout << "ISBN: ";
        string ISBN;
        getline(cin, ISBN);

        //get book title
        cout << "Title: ";
        string title;
        getline(cin, title);

        //get book price
        cout << "Price: ";
        double price;
        cin >> price;
        cout << endl;

        //price calculations
        double subtotal = price * quantity;
        double tax = subtotal * 0.06;
        double total = subtotal + tax;

        //sales slip
        cout << "Serendipity Book Sellers" << endl << endl;
        cout << "Date: " << date << endl << endl;
        cout << "Qty  ISBN           Title                               Price    Total    " << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(5) << quantity << setw(15) << ISBN << setw(36) << title << "$ " << setw(7) << price << "$ " << setw(7) << subtotal << endl << endl << endl;
        cout << right << setw(21) << "Subtotal" << setw(46) << "$ " << subtotal << endl;
        cout << right << setw(16) << "Tax" << setw(52) << "$  " << tax << endl;
        cout << right << setw(18) << "Total" << setw(49) << "$ " << total << endl << endl;

        //asks user for input and stores in the bool repeat
        cout << "Would you like to process another transaction? Yes [1] or No [0]: ";
        cin >> choice;
        while (choice != 0 && choice != 1) {
            cout << endl << "Please enter 1 or 0: ";
            cin >> choice;
        }
        
        cout << endl; cin.ignore(); //formatting, so next print of menu is spaced away from previous sale slip
        
    } while (choice == 1);

    cout << "Thank You for Shopping at Serendipity!" << endl << endl;;
    
    return 0;

    //NOTES:

    //the presentation of the sales slip can be automated depending on the
    //sizes of the biggest book entries for the values that are not constant.
    //values like the title, for example, vary and the title section can be set to the size of the largest title + couple spaces.
    //values like the ISBN will always be the same size so that can be constant
    //definitely need to rewrite menu to be based on variable sizes so formatting is clean for all inputs

    //since ISZBN is a standard size, and QTY is predictable and so is price, use stw to format within the line to give adequate spacing
    //all ISBN numbers are 13 chars long
    //34 is my longest title length
    //three bottom lines start 14 spaces in
    //66 spaces from start to last dollar sign

    //date formatting
}
