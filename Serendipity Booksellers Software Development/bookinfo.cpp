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
int bookInfo() {

    //print menu header
    cout << right << setw(26) << "Serendipity Booksellers" << endl;
    cout << right << setw(22.5) << "Book Information" << endl << endl;

    //prints each type of book data on its own line, no data input yet
    cout << "ISBN: " << endl << "Title: " << endl << "Author: " << endl << "Publisher: " << endl << "Date Added: " << endl << "Quantity-On-Hand: " << endl << "Wholesale Cost: " << endl << "Retail Price: " << endl;

    return 0;
}
