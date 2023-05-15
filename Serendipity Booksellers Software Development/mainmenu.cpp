/*
    File: mainmenu.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays a main menu screen with four options, and allows the user to input a choice.
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
//    //(formatting) prints three empty spaces to the left of the following string,
//    //as the string has a length of 23
//    cout << right << setw(26) << "Serendipity Booksellers" << endl;
//    //(formatting) prints 10 empty spaces to the left of the following string,
//    //as the string has a length of 9
//    cout << right << setw(19) << "Main Menu" << endl << endl;
//    //prints out the four menu options, one on each line, and then asks the user
//    //to enter their choice
//    cout << "1. Cashier Module" << endl << "2. Inventory Database Module" << endl << "3. Report Module" << endl << "4. Exit" << endl << endl << "Enter Your Choice: ";
//
//    //makes an int variable to store the user's choice in, and gets it with cin
//    int choice;
//    cin >> choice;
//    
//    //basic input validation, does not check whether what was entered is an integer
//    if (choice < 1 || choice > 4)
//        cout << endl << "Please enter a number in the range 1-4." << endl;
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
//            //this should never be reached
//            default:
//                cout << "ERROR" << endl;
//                break;
//        }
//    }
//
//    return 0;
//}
