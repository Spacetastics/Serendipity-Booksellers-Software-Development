/*
    File: invmenu.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays the inventory menu screen with four options, and allows the user to input a choice.
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>

//project headers
#include "bookinfo.h"
#include "globals.h"
#include "invmenu.h"

using namespace std;

//inventory function implementations:

//attempts to find a book that the user inputs, provides book information if it is found
void lookUpBook() {
    //ask user for book title
    cout << "Enter the title or part of a title of a book: ";
    char title[MAX_TITLE];
    cin.getline(title, MAX_TITLE);
    strUpper(title); //converts title input to uppercase so that it can properly search the inventory
    cout << endl; //formatting
    
    
    char confirmation;
    for (int i = 0; i < ARR_SIZE; i++) {
        //strstr returns a pointer to the first occurence of the substring in the string, or NULL if not found.
        //If it is not NULL, a match was found.
        if (strstr(inventory[i].bookTitle, title) != NULL) {
            cout << "Is \'" << inventory[i].bookTitle << "\' the book you are looking for? (Y/N): ";
            cin >> confirmation;
            //Ignore any remaining characters in the buffer for the next input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //input validation
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N') {
                cout << endl << "Please enter Y or N: ";
                cin >> confirmation;
                
                //Ignore any remaining characters in the buffer for the next input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            //if book title is found in inventory, rest of book's info is displayed with bookInfo()
            if (toupper(confirmation) == 'Y') {
                cout << endl;
                bookInfo(inventory[i].isbn, inventory[i].bookTitle, inventory[i].author, inventory[i].publisher, inventory[i].dateAdded, inventory[i].qtyOnHand, inventory[i].wholesale, inventory[i].retail);
                return;
            }
            
        }
    }
    
    //title not found in bookTitle
    cout << endl << "No book in inventory matches the provided title." << endl;
}

//if there is space in inventory, adds a book according to user input
void addBook() {
    //loop iterates across the bookTitle array looking for an empty slot to put a new book in
    for (int i = 0; i < ARR_SIZE; i++) {
        
        if (isEmpty(i)) {
            //getting new book data from user
            cout << "Enter the following.." << endl;
            
            //part 10 tells me to call strUpper to convert to uppercase *before* they are added to arrays, but I'm going to do it after because the code is simpler that way and it's the same effect
            cout << "Book title: ";
            char titleInput[MAX_TITLE];
            cin.getline(titleInput, MAX_TITLE);
            strUpper(titleInput); //converts title to uppercase for proper formatting
            setTitle(titleInput, i);
            cout << "ISBN number: ";
            char isbnInput[MAX_ISBN];
            cin >> isbnInput; //isbn will always be one piece, so cin is appropriate
            cin.ignore(); //ignore newline in input buffer
            strUpper(isbnInput); //converts title to uppercase for proper formatting
            setISBN(isbnInput, i);
            cout << "Author's name: ";
            char authorInput[MAX_AUTHOR];
            cin.getline(authorInput, MAX_AUTHOR);
            strUpper(authorInput);
            setAuthor(authorInput, i);
            cout << "Publisher's name: ";
            char publisherInput[MAX_PUBLISHER];
            cin.getline(publisherInput, MAX_PUBLISHER);
            strUpper(publisherInput);
            setPub(publisherInput, i);
            cout << "The date the book was added to the inventory: ";
            char dateInput[MAX_DATE];
            cin >> dateInput; //date will always be one piece, so cin is appropriate
            strUpper(dateInput);
            setDateAdded(dateInput, i);
            cout << "The quantity of the book being added: ";
            int qtyInput;
            cin >> qtyInput;
            setQty(qtyInput, i);
            cout << "The wholesale cost of the book: ";
            double costInput;
            cin >> costInput;
            setWholesale(costInput, i);
            cout << "The retail price of the book: ";
            double priceInput;
            cin >> priceInput;
            setRetail(priceInput, i);
            
            cout << endl << "Book \'" << inventory[i].bookTitle << "\' added to inventory." << endl;
            return;
        }
    }
    
    //bookTitle has no empty strings
    cout << "No more books may be added to the inventory." << endl;
}

//tries to find a book by title that the user provides, and allows the user to edit the book's information if found
void editBook() {
    //ask user for book title
    cout << "Enter the title or part of a title of a book: ";
    char title[MAX_TITLE];
    cin.getline(title, MAX_TITLE);
    strUpper(title); //converts title input to uppercase so that it can properly search the inventory
    cout << endl; //formatting
    
    char confirmation;
    //if book title is found in inventory, displays book information and allows the user to edit what information they want
    for (int i = 0; i < ARR_SIZE; i++) {
        
        //strstr returns a pointer to the first occurence of the substring in the string, or NULL if not found.
        //If it is not NULL, a match was found.
        if (strstr(inventory[i].bookTitle, title) != NULL) {
            cout << "Is \'" << inventory[i].bookTitle << "\' the book you are looking for? (Y/N): ";
            cin >> confirmation;
            //Ignore any remaining characters in the buffer for the next input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //input validation
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N') {
                cout << endl << "Please enter Y or N: ";
                cin >> confirmation;
                
                //Ignore any remaining characters in the buffer for the next input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            //if book title is found in inventory, rest of book's info is displayed with bookInfo(), user is allowed to edit book's info
            if (toupper(confirmation) == 'Y') {
                cout << endl;
                bookInfo(inventory[i].isbn, inventory[i].bookTitle, inventory[i].author, inventory[i].publisher, inventory[i].dateAdded, inventory[i].qtyOnHand, inventory[i].wholesale, inventory[i].retail);
                
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
                            char isbnInput[MAX_ISBN];
                            cin >> isbnInput; //isbn will always be one piece, so cin is appropriate
                            cin.ignore(); //ignore newline in input buffer
                            strUpper(isbnInput); //converts title to uppercase for proper formatting
                            setISBN(isbnInput, i);
                            break;
                        case 2:
                            cout << "Enter new title: ";
                            cin.ignore();
                            char titleInput[MAX_TITLE];
                            cin.getline(titleInput, MAX_TITLE);
                            strUpper(titleInput); //converts title to uppercase for proper formatting
                            setTitle(titleInput, i);
                            break;
                        case 3:
                            cout << "Enter new author: ";
                            cin.ignore();
                            char authorInput[MAX_AUTHOR];
                            cin.getline(authorInput, MAX_AUTHOR);
                            strUpper(authorInput);
                            setAuthor(authorInput, i);
                            break;
                        case 4:
                            cout << "Enter new publisher: ";
                            cin.ignore();
                            char publisherInput[MAX_PUBLISHER];
                            cin.getline(publisherInput, MAX_PUBLISHER);
                            strUpper(publisherInput);
                            setPub(publisherInput, i);
                            break;
                        case 5:
                            cout << "Enter new date added: ";
                            char dateInput[MAX_DATE];
                            cin >> dateInput; //date will always be one piece, so cin is appropriate
                            strUpper(dateInput);
                            setDateAdded(dateInput, i);
                            break;
                        case 6:
                            cout << "Enter new quantity-on-hand: ";
                            int qtyInput;
                            cin >> qtyInput;
                            setQty(qtyInput, i);
                            break;
                        case 7:
                            cout << "Enter new wholesale cost: ";
                            double costInput;
                            cin >> costInput;
                            setWholesale(costInput, i);
                            break;
                        case 8:
                            cout << "Enter new retail price: ";
                            double priceInput;
                            cin >> priceInput;
                            setRetail(priceInput, i);
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
        
    }
    
    //title not found in bookTitle
    cout << endl << "No book in inventory matches the provided title." << endl;
}

//attempts to find book user inputs, allows user to delete it from inventory
void deleteBook() {
    
    //ask user for book title
    cout << "Enter the title or part of a title of a book: ";
    char title[MAX_TITLE];
    cin.getline(title, MAX_TITLE);
    strUpper(title); //converts title input to uppercase so that it can properly search the inventory
    cout << endl; //formatting
    
    char confirmation;
    //if book title is found in inventory, displays book information with bookInfo and deletes it from inventory upon user confirmation
    for (int i = 0; i < ARR_SIZE; i++) {
        
        //strstr returns a pointer to the first occurence of the substring in the string, or NULL if not found.
        //If it is not NULL, a match was found.
        if (strstr(inventory[i].bookTitle, title) != NULL) {
            cout << "Is \'" << inventory[i].bookTitle << "\' the book you are looking for? (Y/N): ";
            cin >> confirmation;
            //Ignore any remaining characters in the buffer for the next input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //input validation
            while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N') {
                cout << endl << "Please enter Y or N: ";
                cin >> confirmation;
                
                //Ignore any remaining characters in the buffer for the next input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            //if book title is found in inventory, rest of book's info is displayed with bookInfo()
            if (toupper(confirmation) == 'Y') {
                cout << endl;
                bookInfo(inventory[i].isbn, inventory[i].bookTitle, inventory[i].author, inventory[i].publisher, inventory[i].dateAdded, inventory[i].qtyOnHand, inventory[i].wholesale, inventory[i].retail);
                
                int choice;
                cout << endl << "Are you sure you want to delete this book? Enter 1 for Yes or 0 for No: ";
                cin >> choice;
                while (choice != 0 && choice != 1) {
                    cout << endl << "Please enter 1 for Yes or 0 for No: ";
                    cin >> choice;
                }
                
                //deletion is done by clearing its bookTitle slot, since this is how books and free space are found
                if (choice == 1) {
                    cout << endl << "Deleted \'" << inventory[i].bookTitle << "\'. " << endl;
                    
                    //deletes here
                    removeBook(i);
                }
                
                return;
                
            }
            
        }
        
    }
    
    //title not found in bookTitle
    cout << endl << "No book in inventory matches the provided title." << endl;
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
    
    //date is MM-DD-YYYY, need to add input validation
    //add more feedback. ex, for editBook print text confirming the change, for deleteBook confirm the deletion, etc.
    //confirm the menu choice that the use picks with cout
    //update header comment
}
