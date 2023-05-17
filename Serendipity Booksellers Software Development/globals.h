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

//these global variables are defined in invmenu.cpp and used in invmenu.cpp, cashier.cpp, and reports.cpp

//extern keyword is used here to tell the compiler that these variables are defined in a different file, so that
//every file that includes this header will all share the same references to these variables instead of using distinct copies

//size of all the below arrays
//maybe change name for c string implementation
extern const int ARR_SIZE;

//global arrays for book information
extern char bookTitle[][51];
extern char isbn[][14];
extern char author[][31];
extern char publisher[][31];
extern char dateAdded[][11];
extern int qtyOnHand[];
extern double wholesale[];
extern double retail[];

#endif /* globals_h */
