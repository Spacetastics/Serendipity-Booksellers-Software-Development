/*
    File: invmenu.h
    Project: Serendipity Booksellers Software Development
    Purpose: invmenu.cpp header file
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

#ifndef invmenu_h
#define invmenu_h

//helper functions
//I assume by string part 10 meant c string
void strUpper(char* str); //may move to globals if necessary

//inventory functions
void lookUpBook();
void addBook();
void editBook();
void deleteBook();

//main function
int invMenu();

#endif /* invmenu_h */
