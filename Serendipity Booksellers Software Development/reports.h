/*
    File: reports.h
    Project: Serendipity Booksellers Software Development
    Purpose: reports.cpp header file
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

#ifndef reports_h
#define reports_h

#include <string>

using std::string;

//helper function (not provided by projects)
bool isOlder(const char* date1, const char* date2); //const references are more efficient than passing by value

//report functions
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

//main function
int reports();

#endif /* reports_h */
