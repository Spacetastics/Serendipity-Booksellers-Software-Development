/*
    File: globals.h
    Project: Serendipity Booksellers Software Development
    Purpose: contains global variables to be used across multiple files
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

#ifndef globals_h
#define globals_h

#include <string>

using std::string;

//these global variables are defined in invmenu.cpp and used in invmenu.cpp, cashier.cpp, and reports.cpp

//extern keyword is used here to tell the compiler that these variables are defined in a different file, so that
//every file that includes this header will all share the same references to these variables instead of using distinct copies

//size of all the below arrays
extern const int ARR_SIZE;

//global arrays for book information
extern string bookTitle[];
extern string isbn[];
extern string author[];
extern string publisher[];
extern string dateAdded[];
extern int qtyOnHand[];
extern double wholesale[];
extern double retail[];

#endif /* globals_h */
