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
//    //makes an int variable to store the user's choice
//    int choice;
//    //continually asks the user to enter a choice until they enter 5 (return to main menu)
//    do {
//        
//        //print header
//        cout << right << setw(26) << "Serendipity Booksellers" << endl;
//        cout << right << setw(23.5) << "Inventory Database" << endl << endl;
//
//        //print five options
//        cout << "1. Look Up a Book" << endl << "2. Add a Book" << endl << "3. Edit a Book's Record" << endl << "4. Delete a Book" << endl << "5. Return to the Main Menu" << endl << endl;
//        
//        //asks user for input and stores console input in choice
//        cout << "Enter Your Choice: ";
//        cin >> choice;
//        
//        //basic input validation, does not check whether what was entered is an integer
//        while (choice < 1 || choice > 5) {
//            cout << endl << "Please enter a number in the range 1-5: ";
//            cin >> choice;
//            cin.ignore(); //this stops the console output from being flooded by the above output due to my second endl insertion in the following switch statement
//        }
//        
//        cout << endl << "You selected item ";
//        switch (choice) {
//            case 1:
//                cout << "1." << endl << endl;
//                break;
//            case 2:
//                cout << "2." << endl << endl;
//                break;
//            case 3:
//                cout << "3." << endl << endl;
//                break;
//            case 4:
//                cout << "4." << endl << endl;
//                break;
//            case 5:
//                cout << "5." << endl << endl;
//                break;
//            //this should never be reached
//            default:
//                cout << "ERROR" << endl;
//                break;
//        }
//        
//    } while (choice != 5);
//    
//}
