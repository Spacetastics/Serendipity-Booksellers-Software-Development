/*
    File: bookinfo.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays a screen that shows information for a book
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <iostream>
#include <iomanip>

//project headers
#include "bookinfo.h"

using namespace std;

//main function implementation
int bookInfo(char isbn[14], char title[51], char author[31], char publisher[31], char date[11], int qty, double wholesale, double retail) {

    //print menu header
    cout << right << setw(26) << "Serendipity Booksellers" << endl;
    cout << right << setw(22.5) << "Book Information" << endl << endl;

    //prints each type of book data on its own line
    cout << "1. ISBN: " << isbn << endl
    << "2. Title: " << title << endl
    << "3. Author: " << author << endl
    << "4. Publisher: " << publisher << endl
    << "5. Date Added: " << date << endl
    << "6. Quantity-On-Hand: " << qty << endl
    << "7. Wholesale Cost: " << wholesale << endl
    << "8. Retail Price: " << retail << endl;

    return 0;
    
    //NOTES:
    
    //might want to change variables in function to const reference for efficiency reasons (more efficient than copying/passing by value)
}
