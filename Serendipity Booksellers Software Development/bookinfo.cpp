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
#include <string>

//project headers
#include "bookinfo.h"

using namespace std;

//main function implementation
int bookInfo(string isbn, string title, string author, string publisher, string date, int qty, double wholesale, double retail) {

    //print menu header
    cout << right << setw(26) << "Serendipity Booksellers" << endl;
    cout << right << setw(22.5) << "Book Information" << endl << endl;

    //prints each type of book data on its own line
    cout << "ISBN: " << isbn << endl
    << "Title: " << title << endl
    << "Author: " << author << endl
    << "Publisher: " << publisher << endl
    << "Date Added: " << date << endl
    << "Quantity-On-Hand: " << qty << endl
    << "Wholesale Cost: " << wholesale << endl
    << "Retail Price: " << retail << endl;

    return 0;
}
