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
#include <vector> //may need to delete later

//project headers
#include "cashier.h"
#include "globals.h"

using namespace std;

//main function implementation
int cashier() {
    //no input validation at the moment
    
    //makes an int variable to store a users choice
    int transactionChoice;
    //shopping loop, allows user to buy books and print sale slips
    do {
        //possibly a temporary implementation for keeping track of multiple buys, may need to delete later
        //this vector holds the indices of all books that the user would like to purchase, if there is sufficient stock
        vector<int> booksPurchased;
        //this vector holds the desired quantity of purchased books, entry indices correspond to indices stored in above vector
        vector<int> bookQuantities;
        
        //print out header
        cout << right << setw(26) << "Serendipity Booksellers" << endl;
        cout << right << setw(21.5) << "Cashier Module" << endl << endl;

        //get sales data:

        //get sale date. should only happen once per iteration
        cout << "Sale Date: ";
        string date;
        getline(cin, date);
        cout << endl; //formatting
        
        //allows user to input quantity and ISBN of desired book, stores found books in booksPurchased for printing and calculations later
        bool inputBook = true;
        do {
            
            //get number of this book purchased, verifies quantity is valid (at least 1)
            cout << "Quantity of Book: ";
            int quantity;
            cin >> quantity;
            while (quantity < 1) {
                cout << endl << "Quantity must be at least 1: ";
                cin >> quantity;
            }

            //get book ISBN to find if requested book is in inventory
            char isbnNum[MAX_ISBN];

            //attempts to find book of provided ISBN in inventory, stores index of book in booksPurchased if found
            bool found = false;
            do {
                cout << endl << "ISBN: ";
                cin >> isbnNum;
                strUpper(isbnNum);
                cout << endl;
                
                for (int i = 0; i < ARR_SIZE; i++) {
                    
                    if (strcmp(inventory[i].isbn, isbnNum) == 0) {
                        //determines if there is enough stock to buy as many as user requested
                        //project description wants me to put thes *after* getting book data, but it also just wants me to return to the main menu after finding there isn't enough in stock, so I'm putting it first.
                        if (inventory[i].qtyOnHand < quantity) {
                            cout << "There are not enough copies in stock to fulfill your order. There are " << inventory[i].qtyOnHand << " copies in stock." << endl;
                            
                            //must go to next iteration of loop instead of returning to main menu because of multiple book entries
                            goto end_of_loop;
                            
                        }
                        else {
                            //must store bought quantity somewhere before subtracting, so it can be used for later calculations
                            bookQuantities.push_back(quantity);
                            inventory[i].qtyOnHand -= quantity;
                        }
                        
                        //book data retrieved
                        //commented out in favor of the booksPurchased vector which will instead store the index of the book that was just found, and will access the two pieces of information later
//                        title = bookTitle[i];
//                        price = retail[i];
                        
                        booksPurchased.push_back(i);
                        found = true;
                        break;
                    }
                    
                }
                
                if (!found) {
                    cout << "The ISBN \'" << isbnNum << "\' was not found in inventory." << endl << endl;
                    cout << "Would you like to re-enter the ISBN number? Enter 1 for Yes or 0 for No: ";
                    int input;
                    cin >> input;
                    while (input != 0 && input != 1) {
                        cout << endl << "Please enter 1 for Yes or 0 for No: ";
                        cin >> input;
                    }
                    
                    if (input == 0)
                        break;

                }
                else
                    cout << "Book added to cart" << endl;
                
            } while (!found);
            
            //tag for quantity condition in for loop
            end_of_loop:
            
            //input to check if buy loop should continue
            cout << endl << "Are there other titles being purchased today? Enter 1 for Yes or 0 for No: ";
            int input;
            cin >> input;
            while (input != 0 && input != 1) {
                cout << endl << "Please enter 1 for Yes or 0 for No: ";
                cin >> input;
            }
            cout << endl; //formatting for next re-loop
            
            if (input == 0)
                inputBook = false;
            
            
        } while (inputBook);
        cin.ignore(); //this may not be necessary

        //returns to main menu if no books were successfully found
        if (booksPurchased.size() == 0) {
            cout << "No books were purchased, returning to Main Menu..." << endl << endl;
            return 0;
        }
        
        
        
        //sales slip
        cout << "Serendipity Book Sellers" << endl << endl;
        cout << "Date: " << date << endl << endl;
        cout << "Qty  ISBN           Title                               Price    Total    " << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << fixed << setprecision(2);
        
        double subtotal = 0.0;
        for (int i = 0; i < booksPurchased.size(); i++) {
            double bookSubtotal = inventory[booksPurchased.at(i)].retail * bookQuantities.at(i);
            
            cout << left << setw(5) << bookQuantities.at(i) << setw(15) << inventory[booksPurchased.at(i)].isbn << setw(36) << inventory[booksPurchased.at(i)].bookTitle << "$ " << setw(7) << inventory[booksPurchased.at(i)].retail << "$ " << setw(7) << bookSubtotal << endl;
            
            subtotal += bookSubtotal;
        }
        cout << endl << endl; //formatting
        
        //price calculations
        double tax = subtotal * 0.06;
        double total = subtotal + tax;
        
        cout << right << setw(21) << "Subtotal" << setw(46) << "$ " << subtotal << endl;
        cout << right << setw(16) << "Tax" << setw(52) << "$  " << tax << endl;
        cout << right << setw(18) << "Total" << setw(49) << "$ " << total << endl << endl;

        //asks user for input and stores in the bool repeat
        cout << "Would you like to process another transaction? Yes [1] or No [0]: ";
        cin >> transactionChoice;
        while (transactionChoice != 0 && transactionChoice != 1) {
            cout << endl << "Please enter 1 or 0: ";
            cin >> transactionChoice;
        }
        
        cout << endl; cin.ignore(); //formatting, so next print of menu is spaced away from previous sale slip
        
    } while (transactionChoice == 1);

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
    //add functions to some common header file for common procedures (such as input validation)
}
