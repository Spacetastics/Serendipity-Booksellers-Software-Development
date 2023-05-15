/*
    File: invmenu.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays the inventory menu screen with four options, and allows the user to input a choice.
    Author: Noah Cil
    Professor: Ping-Wei Tsai
    Class: CMSC 226 (30145)
 */

#include <iostream>
#include <iomanip>

using namespace std;

//main method must be commented out at the moment because I am using separate files for everything

//int main() {
//
//    //print header
//    cout << right << setw(26) << "Serendipity Booksellers" << endl;
//    cout << right << setw(23.5) << "Inventory Database" << endl << endl;
//
//    //print four options and ask user to enter choice
//    cout << "1. Look Up a Book" << endl << "2. Add a Book" << endl << "3. Edit a Book's Record" << endl << "4. Delete a Book" << endl << "5. Return to the Main Menu" << endl << endl << "Enter Your Choice: ";
//
//    //makes an int variable to store the user's choice in, and gets it with cin
//    int choice;
//    cin >> choice;
//
//    //basic input validation, does not check whether what was entered is an integer
//    if (choice < 1 || choice > 5)
//        cout << endl << "Please enter a number in the range 1-5." << endl;
//    else {
//        cout << endl << "You selected item ";
//        switch (choice) {
//            case 1:
//                cout << "1." << endl;
//                break;
//            case 2:
//                cout << "2." << endl;
//                break;
//            case 3:
//                cout << "3." << endl;
//                break;
//            case 4:
//                cout << "4." << endl;
//                break;
//            case 5:
//                cout << "5." << endl;
//                break;
//            //this should never be reached
//            default:
//                cout << "ERROR" << endl;
//                break;
//        }
//    }
//
//}
