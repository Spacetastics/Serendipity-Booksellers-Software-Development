/*
    File: sharedfunctions.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Defines several functions which are used across multiple files
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

//standard library headers
#include <cctype>
#include <cstring>

//project headers
#include "globals.h"

using namespace std;

const int ARR_SIZE = 20;

BookData inventory[ARR_SIZE];

//helper function implementation
//capitalizes inputted string
void strUpper(char* str) {
    
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = toupper(str[i]);
    }
    
}

//copies title to bookTitle in the entry at index in inventory
void setTitle(const char* title, int index) {
    //copies title to bookTitle c string in the BookData struct at index, MAX_TITLE makes sure no more characters are copied than can fit into bookTitle
    strncpy(inventory[index].bookTitle, title, MAX_TITLE);
    inventory[index].bookTitle[MAX_TITLE -1] = '\0'; //ensure null termination by setting last index of bookTitle to null
}

//copies isbn to isbn in the entry at index in inventory
void setISBN(const char* isbn, int index) {
    //copies isbn to isbn c string in the BookData struct at index, MAX_ISBN makes sure no more characters are copied than can fit into isbn
    strncpy(inventory[index].isbn, isbn, MAX_ISBN);
    inventory[index].isbn[MAX_ISBN -1] = '\0'; //ensure null termination by setting last index of isbn to null
}

//copies author to author in the entry at index in inventory
void setAuthor(const char* author, int index) {
    //copies author to author c string in the BookData struct at index, MAX_AUTHOR makes sure no more characters are copied than can fit into author
    strncpy(inventory[index].author, author, MAX_AUTHOR);
    inventory[index].author[MAX_AUTHOR -1] = '\0'; //ensure null termination by setting last index of author to null
}

//copies publisher to publisher in the entry at index in inventory
void setPub(const char* publisher, int index) {
    //copies publisher to publisher c string in the BookData struct at index, MAX_PUBLISHER makes sure no more characters are copied than can fit into publisher
    strncpy(inventory[index].publisher, publisher, MAX_PUBLISHER);
    inventory[index].publisher[MAX_PUBLISHER -1] = '\0'; //ensure null termination by setting last index of publisher to null
}

//copies date to dateAdded in the entry at index in inventory
void setDateAdded(const char* date, int index) {
    //copies date to dateAdded c string in the BookData struct at index, MAX_DATE makes sure no more characters are copied than can fit into dateAdded
    strncpy(inventory[index].dateAdded, date, MAX_DATE);
    inventory[index].dateAdded[MAX_DATE -1] = '\0'; //ensure null termination by setting last index of date to null
}

//copies quantity to qtyOnHand in the entry at index in inventory
void setQty(const int quantity, int index) {
    inventory[index].qtyOnHand = quantity;
}

//copies cost to wholesale in the entry at index in inventory
void setWholesale(const double cost, int index) {
    inventory[index].wholesale = cost;
}

//copies price to retail in the entry at index in inventory
void setRetail(const double price, int index) {
    inventory[index].retail = price;
}

//returns 1 if bookTitle at index is empty, otherwise returns 0
int isEmpty(int index) {
    if (strcmp(inventory[index].bookTitle, "") == 0)
        return 1;
    return 0;
}

//removes book from inventory by setting the first character of bookTitle at index to null terminator
void removeBook(int index) {
    inventory[index].bookTitle[0] = '\0';
    inventory[index].isbn[0] = '\0';
}
