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
extern const int ARR_SIZE;

//anonymous enums that hold the size of their respective c strings
enum {
    MAX_TITLE = 51,
    MAX_ISBN = 14,
    MAX_AUTHOR = 31,
    MAX_PUBLISHER = 31,
    MAX_DATE = 11
};

//structure replaces the several arrays
struct BookData {
    char bookTitle[MAX_TITLE]; //title c string, holds up to a 50 character title
    char isbn[MAX_ISBN]; //isbn c string, holds up to a 13 character isbn
    char author[MAX_AUTHOR]; //author c string, holds up to 30 character author name
    char publisher[MAX_PUBLISHER]; //publisher c string, holds up to 30 character publisher name
    char dateAdded[MAX_DATE]; //date c string, MM-DD-YYYY
    int qtyOnHand; //holds the quantity on hand of a book
    double wholesale; //holds the wholesale cost of a book
    double retail; //holds the retail price of a book
};

//global array of structs
extern BookData inventory[];

//shared functions
void setTitle(const char* title, int index);
void setISBN(const char* isbn, int index);
void setAuthor(const char* author, int index);
void setPub(const char* publisher, int index);
void setDateAdded(const char* date, int index);
void setQty(const int quantity, int index);
void setWholesale(const double cost, int index);
void setRetail(const double price, int index);
int isEmpty(int index);
void removeBook(int index);

//helper functions
//I assume by string part 10 meant c string
void strUpper(char* str);

#endif /* globals_h */
