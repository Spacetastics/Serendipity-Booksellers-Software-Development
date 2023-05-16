/*
    File: bookinfo.h
    Project: Serendipity Booksellers Software Development
    Purpose: bookinfo.cpp header file
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

#ifndef bookinfo_h
#define bookinfo_h

#include <string>

using std::string;

//main function
int bookInfo(string isbn, string title, string author, string publisher, string date, int qty, double wholesale, double retail);

#endif /* bookinfo_h */
