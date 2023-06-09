/*
    File: reports.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays the reports menu screen with 7 options, and allows the user to input a choice.
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <cstdlib> //for helper function
#include <cstring> //for helper function
#include <ctime> //for getting current date for some report functions
#include <iostream>
#include <iomanip>
#include <string>

//project headers
#include "reports.h"
#include "globals.h"

using namespace std;

//custom helper function implementation:
//returns true if first date is older, false if second date is older; changed implementation to work with c strings
bool isOlder(const char* date1, const char* date2) {
    //date format is MM-DD-YYYY
    
    int month1, day1, year1;
    int month2, day2, year2;

    sscanf(date1, "%d-%d-%d", &month1, &day1, &year1);
    sscanf(date2, "%d-%d-%d", &month2, &day2, &year2);

    if (year1 != year2) {
        return year1 < year2;
    }
    if (month1 != month2) {
        return month1 < month2;
    }
    return day1 < day2;
}

//report function implementations:

//displays a report listing the information of all the books in inventory.
void repListing() {
    
    //gets current date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    
    //prints title of report and todays date
    cout << "Inventory as of " << put_time(localTime, "%m/%d/%Y") << ": " << endl << endl;
    
    //prints all book information, books are in the order that they are found in bookTitle
    for (int i = 0; i < ARR_SIZE; i++) {
        if (!isEmpty(i)) {
            //prints each type of book data on its own line
            cout << "Title: " << inventory[i].bookTitle << endl
            << "ISBN: " << inventory[i].isbn << endl
            << "Author: " << inventory[i].author << endl
            << "Publisher: " << inventory[i].publisher << endl
            << "Date Added to Inventory: " << inventory[i].dateAdded << endl
            << "Quantity-On-Hand: " << inventory[i].qtyOnHand << endl
            << "Wholesale Cost: $" << inventory[i].wholesale << endl
            << "Retail Price: $" << inventory[i].retail << endl;
            
            cout << "------------------------------------" << endl; //separator for books
        }
    }
    
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    if (cin.get() != '\n') //waits for user to press enter, discards extra input if any
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard any remaining input
    
    //project says "continue to the next screen." I don't know what "next screen" is supposed to be so I'm just going back to the reports menu
    
}

//displays a report that lists some book data and gives wholesale value of inventory
void repWholesale() {
  
    //gets current date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    
    //prints title of report and todays date
    cout << "Wholesale report for " << put_time(localTime, "%m/%d/%Y") << ": " << endl << endl;
    
    //variable to store total wholesale value of books
    double wholesaleTotal = 0.0;
    
    //prints essential book information + wholesale cost, books are in the order they are found in bookTitle
    for (int i = 0; i < ARR_SIZE; i++) {
        if (!isEmpty(i)) {
            //prints each type of book data on its own line
            cout << "Title: " << inventory[i].bookTitle << endl
            << "ISBN: " << inventory[i].isbn << endl
            << "Quantity-On-Hand: " << inventory[i].qtyOnHand << endl
            << "Wholesale Cost: $" << inventory[i].wholesale << endl;
            
            cout << "------------------------------------" << endl; //separator for books
            
            //adds total wholesale cost of current book to wholesaleTotal
            wholesaleTotal += (inventory[i].wholesale * inventory[i].qtyOnHand);
        }
    }
    
    cout << "Inventory wholesale value: $" << wholesaleTotal << endl;
    
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    if (cin.get() != '\n') //waits for user to press enter, discards extra input if any
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard any remaining input
    
}

//displays a report that lists some book data and gives retail value of inventory
void repRetail() {
    
    //gets current date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    
    //prints title of report and todays date
    cout << "Retail report for " << put_time(localTime, "%m/%d/%Y") << ": " << endl << endl;
    
    //variable to store total retail value of books
    double retailTotal = 0.0;
    
    //prints essential book information + retail cost, books are in the order they are found in bookTitle
    for (int i = 0; i < ARR_SIZE; i++) {
        if (!isEmpty(i)) {
            //prints each type of book data on its own line
            cout << "Title: " << inventory[i].bookTitle << endl
            << "ISBN: " << inventory[i].isbn << endl
            << "Quantity-On-Hand: " << inventory[i].qtyOnHand << endl
            << "Retail Price: $" << inventory[i].retail << endl;
            
            cout << "------------------------------------" << endl; //separator for books
            
            //adds total retail value of current book to retailTotal
            retailTotal += (inventory[i].retail * inventory[i].qtyOnHand);
        }
    }
    
    cout << "Inventory retail value: $" << retailTotal << endl;
    
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    if (cin.get() != '\n') //waits for user to press enter, discards extra input if any
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard any remaining input
    
}


//displays report that lists some book data for books that are sorted in descending order according to quantity
void repQty() {
    
    //gets current date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    
    //prints title of report and todays date
    cout << "Quantity report for " << put_time(localTime, "%m/%d/%Y") << ": " << endl << endl;
    
    //array of pointers to int values
//    int* qtyPtr[ARR_SIZE];
    BookData* qtyPtr[ARR_SIZE];
    
    int ptrIndex = 0; //index counter for qtyPtr
    //initializes qtyPtr pointer array to memory addresses of values in qtyOnHand
    for (int i = 0; i < ARR_SIZE; i++) {
        //if there is a book at this index
        if (!isEmpty(i)) {
//            qtyPtr[ptrIndex] = .qtyOnHand;
            qtyPtr[ptrIndex] = &inventory[i];
            
            ptrIndex++;
        }
    }
    
    //selection sort qtyPtr memory addresses based on value of what they point to in qtyOnHand
    for (int i = 0; i < ptrIndex - 1; i++) {
        int maxIndex = i;
        
        for (int j = i + 1; j < ptrIndex; j++) {
            
            if (qtyPtr[j]->qtyOnHand > qtyPtr[maxIndex]->qtyOnHand)
                maxIndex = j;
            
        }
        
        if (maxIndex != i)
            swap(qtyPtr[i], qtyPtr[maxIndex]);
    }
    
    for (int i = 0; i < ptrIndex; i++) {
        //gets index of the value in qtyOnHand that qtyPtr points to at i
        //this gives me a warning for some reason so I added the pragma line to ignore it
        #pragma clang diagnostic ignored "-Wconversion"
        int index = qtyPtr[i] - inventory;
        
        //prints each type of book data on its own line
        cout << "Title: " << inventory[index].bookTitle << endl
        << "ISBN: " << inventory[index].isbn << endl
        << "Quantity-On-Hand: " << inventory[index].qtyOnHand << endl;
        
        cout << "------------------------------------" << endl; //separator for books
    }
    
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    if (cin.get() != '\n') //waits for user to press enter, discards extra input if any
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard any remaining input
    
}

//displays report that lists some book data for books that are sorted in descending order according to wholesale cost
void repCost() {
    
    //gets current date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    
    //prints title of report and todays date
    cout << "Wholesale Cost report for " << put_time(localTime, "%m/%d/%Y") << ": " << endl << endl;
    
    //array of pointers to double values
//    double* wholesalePtr[ARR_SIZE];
    BookData* wholesalePtr[ARR_SIZE];
    
    int ptrIndex = 0; //index counter for wholesalePtr
    //initializes wholesalePtr pointer array to memory addresses of values in wholesale
    for (int i = 0; i < ARR_SIZE; i++) {
        //if there is a book at this index
        if (!isEmpty(i)) {
            wholesalePtr[ptrIndex] = &inventory[i];
            ptrIndex++;
        }
    }
    
    //selection sort wholesalePtr memory addresses based on value of what they point to in wholesale
    for (int i = 0; i < ptrIndex - 1; i++) {
        int maxIndex = i;
        
        for (int j = i + 1; j < ptrIndex; j++) {

            if (wholesalePtr[j]->wholesale > wholesalePtr[maxIndex]->wholesale)
                maxIndex = j;
            
        }
        
        if (maxIndex != i)
            swap(wholesalePtr[i], wholesalePtr[maxIndex]);
    }
    
    for (int i = 0; i < ptrIndex; i++) {
        //gets index of the value in wholesale that wholesalePtr points to at i
        int index = wholesalePtr[i] - inventory;
        
        //prints each type of book data on its own line
        cout << "Title: " << inventory[index].bookTitle << endl
        << "ISBN: " << inventory[index].isbn << endl
        << "Quantity-On-Hand: " << inventory[index].qtyOnHand << endl
        << "Wholesale Cost: $" << inventory[index].wholesale << endl;
        
        cout << "------------------------------------" << endl;
        
    }
    
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    if (cin.get() != '\n') //waits for user to press enter, discards extra input if any
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard any remaining input
    
}

void repAge() {
    
    //gets current date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    
    //prints title of report and todays date
    cout << "Book Age report for " << put_time(localTime, "%m/%d/%Y") << ": " << endl << endl;
    
    //array of pointers to char values (for c strings)
//    char* datePtr[ARR_SIZE];
    BookData* datePtr[ARR_SIZE];
    
    int ptrIndex = 0; //index counter for datePtr
    //initializes datePtr pointer array to memory addresses of values in dateAdded
    for (int i = 0; i < ARR_SIZE; i++) {
        //if there is a book at this index
        if (!isEmpty(i)) {
            datePtr[ptrIndex] = &inventory[i];
            ptrIndex++;
        }
    }
    
    //selection sort datePtr memory addresses based on value of what they point to in dateAdded
    for (int i = 0; i < ptrIndex - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < ptrIndex; j++) {
            
            if (isOlder(datePtr[j]->dateAdded, datePtr[minIndex]->dateAdded)) //call to helper function to determine which date is older
                minIndex = j;
            
        }
        
        if (minIndex != i)
            swap(datePtr[i], datePtr[minIndex]);
    }
    
    for (int i = 0; i < ptrIndex; i++) {
        //gets index of the value in dateAdded that datePtr points to at i
//        int index = datePtr[i] - dateAdded;
        //previous index implementation no longer works after switching to c strings, so I must Loop
        int index = 0;
        for (int j = 0; j < ARR_SIZE; j++) {
            if (datePtr[i] == &inventory[j]) {
                index = j;
                break;
            }
        }
        
        //prints each type of book data on its own line
        cout << "Title: " << inventory[index].bookTitle << endl
        << "ISBN: " << inventory[index].isbn << endl
        << "Quantity-On-Hand: " << inventory[index].qtyOnHand << endl
        << "Date Added to Inventory: " << inventory[index].dateAdded << endl;
        
        cout << "------------------------------------" << endl; //separator for books
        
    }
    
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    if (cin.get() != '\n') //waits for user to press enter, discards extra input if any
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard any remaining input
    
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
    
    //NOTES:
    
    //change the printed menus in the reports functions to have labels on top, then a separating bar, then list each book's data in one row one after the other like a normal table
}
