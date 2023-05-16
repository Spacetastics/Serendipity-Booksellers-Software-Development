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
#include "bookinfo.h"
#include "invmenu.h"

using namespace std;

const int ARR_SIZE = 20;

//global arrays for book information
//data for a book is linked through subscripts
string bookTitle[ARR_SIZE];
string isbn[ARR_SIZE];
string author[ARR_SIZE];
string publisher[ARR_SIZE];
string dateAdded[ARR_SIZE];
int qtyOnHand[ARR_SIZE];
double wholesale[ARR_SIZE];
double retail[ARR_SIZE];

//TEST ARRAYS, comment above and below in and out accordingly
//const int ARR_SIZE = 1;
//string bookTitle[ARR_SIZE] = {"History of Scotland"}; //for lookUpBook, editBook, deleteBook
////string bookTitle[ARR_SIZE]; //for addBook
//string isbn[ARR_SIZE] = {"0-333-90123-8"};
//string author[ARR_SIZE] = {"S. Historian"};
//string publisher[ARR_SIZE] = {"History Books"};
//string dateAdded[ARR_SIZE] = {"05-24-12"};
//int qtyOnHand[ARR_SIZE] = {2};
//double wholesale[ARR_SIZE] = {9.99};
//double retail[ARR_SIZE] = {19.95};

//inventory function implementations:

//attempts to find a book that the user inputs, provides book information if it is found
void lookUpBook() {
    //ask user for book title
    cout << "Enter the title of a book: ";
    string title;
    getline(cin, title);
    cout << endl; //formatting
    
    //if book title is found in inventory, rest of book's info is displayed with bookInfo()
    for (int i = 0; i < ARR_SIZE; i++) {
        if (bookTitle[i] == title) {
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
            
            return;
        }
    }
    
    //title not found in bookTitle
    cout << "This book is not in inventory." << endl;
}

//if there is space in inventory, adds a book according to user input
void addBook() {
    //loop iterates across the bookTitle array looking for an empty slot to put a new book in
    for (int i = 0; i < ARR_SIZE; i++) {
        //the null terminator is equivalent to "", so I don't need to check for both individually
        if (bookTitle[i] == "") {
            //getting new book data from user
            cout << "Enter the following.." << endl;
            
            cout << "Book title: ";
            getline(cin, bookTitle[i]);
            cout << "ISBN number: ";
            cin >> isbn[i]; //isbn will always be one piece, so cin is appropriate
            cin.ignore(); //ignore newline in input buffer
            cout << "Author's name: ";
            getline(cin, author[i]);
            cout << "Publisher's name: ";
            getline(cin, publisher[i]);
            cout << "The date the book was added to the inventory: ";
            cin >> dateAdded[i]; //date will always be one piece, so cin is appropriate
            cout << "The quantity of the book being added: ";
            cin >> qtyOnHand[i];
            cout << "The wholesale cost of the book: ";
            cin >> wholesale[i];
            cout << "The retail price of the book: ";
            cin >> retail[i];
            
            return;
        }
    }
    
    //bookTitle has no empty strings
    cout << "No more books may be added to the inventory." << endl;
}

//tries to find a book by title that the user provides, and allows the user to edit the book's information if found
void editBook() {
    //ask user for book title
    cout << "Enter the title of a book: ";
    string title;
    getline(cin, title);
    cout << endl; //formatting
    
    //if book title is found in inventory, displays book information and allows the user to edit what information they want
    for (int i = 0; i < ARR_SIZE; i++) {
        if (bookTitle[i] == title) {
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
            
            int choice;
            do {
                cout << endl << "Enter the number of the element you would like to edit, or 0 to stop editing: ";
                cin >> choice;
                //basic input validation, does not check whether what was entered is an integer
                while (choice < 0 || choice > 8) {
                    cout << endl << "Please enter a number in the range 1-8, or 0 to stop editing: ";
                    cin >> choice;
                }

                cout << endl; //formatting
                //the cases are numbered according to how the data is numbered in the bookInfo display
                switch (choice) {
                    case 0:
                        cout << "Returning..." << endl;
                        break;
                    case 1:
                        cout << "Enter new ISBN: ";
                        cin >> isbn[i];
                        break;
                    case 2:
                        cout << "Enter new title: ";
                        cin.ignore();
                        getline(cin, bookTitle[i]);
                        break;
                    case 3:
                        cout << "Enter new author: ";
                        cin.ignore();
                        getline(cin, author[i]);
                        break;
                    case 4:
                        cout << "Enter new publisher: ";
                        cin.ignore();
                        getline(cin, publisher[i]);
                        break;
                    case 5:
                        cout << "Enter new date added: ";
                        cin >> dateAdded[i];
                        break;
                    case 6:
                        cout << "Enter new quantity-on-hand: ";
                        cin >> qtyOnHand[i];
                        break;
                    case 7:
                        cout << "Enter new wholesale cost: ";
                        cin >> wholesale[i];
                        break;
                    case 8:
                        cout << "Enter new retail price: ";
                        cin >> retail[i];
                        break;
                    //this should never be reached
                    default:
                        cout << "ERROR" << endl;
                        break;
                }
            } while (choice != 0);
            
//            //FOR TESTING PURPOSES
//            cout << endl << "FOR TESTING PURPOSES: " << endl;
//            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]); //FOR TESTING PURPOSES
            
            return;
        }
    }
    
    //title not found in bookTitle
    cout << endl << "This book is not in inventory." << endl;
}

//attempts to find book user inputs, allows user to delete it from inventory
void deleteBook() {
    //ask user for book title
    cout << "Enter the title of a book: ";
    string title;
    getline(cin, title);
    cout << endl; //formatting
    
    //if book title is found in inventory, displays book information with bookInfo and deletes it from inventory upon user confirmation
    for (int i = 0; i < ARR_SIZE; i++) {
        if (bookTitle[i] == title) {
            bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
            
            int choice;
            cout << endl << "Are you sure you want to delete this book? Enter 1 for Yes or 0 for No: ";
            cin >> choice;
            while (choice != 0 && choice != 1) {
                cout << endl << "Please enter 1 for Yes or 0 for No: ";
                cin >> choice;
            }
            
            //deletion is done by clearing its bookTitle slot, since this is how books and free space are found
            if (choice == 1) {
                bookTitle[i] = "";
                isbn[i] = "";
            }
            
            return;
        }
    }
    
    //title not found in bookTitle
    cout << "This book is not in inventory." << endl;
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
        cin.ignore(); //ignores newline in input buffer so input is not messed up

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
    
    //NOTES:
    
    //date is MM-DD-YYYY
    //add more feedback. ex, for editBook print text confirming the change, for deleteBook confirm the deletion, etc.
    //confirm the menu choice that the use picks with cout
    //update header comment
}
