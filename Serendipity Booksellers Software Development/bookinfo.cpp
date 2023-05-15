/*
    File: bookinfo.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays a screen that shows information for a book
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

#include <iostream>
#include <iomanip>

using namespace std;

//main method must be commented out at the moment because I am using separate files for everything

int main() {
    
    //print menu header
    cout << right << setw(26) << "Serendipity Booksellers" << endl;
    cout << right << setw(22.5) << "Book Information" << endl << endl;
    
    //prints each type of book data on its own line, no data input yet
    cout << "ISBN: " << endl << "Title: " << endl << "Author: " << endl << "Publisher: " << endl << "Date Added: " << endl << "Quantity-On-Hand: " << endl << "Wholesale Cost: " << endl << "Retail Price: " << endl;
    
}
