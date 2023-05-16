/*
    File: reports.cpp
    Project: Serendipity Booksellers Software Development
    Purpose: Displays the reports menu screen with 7 options, and allows the user to input a choice.
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
//    //continually asks the user to enter a choice until they enter 7 (main menu)
//    do {
//
//        //print header
//        cout << right << setw(26) << "Serendipity Booksellers" << endl;
//        cout << right << setw(18) << "Reports" << endl << endl;
//
//        //print seven options and ask user to input choice
//        cout << "1. Inventory Listing" << endl << "2. Inventory Wholesale Value" << endl << "3. Inventory Retail Value" << endl << "4. Listing by Quantity" << endl << "5. Listing by Cost" << endl << "6. Listing by Age" << endl << "7. Return to Main Menu" << endl << endl;
//
//        //asks user for input and stores console input in choice
//        cout << "Enter Your Choice: ";
//        cin >> choice;
//
//        //basic input validation, does not check whether what was entered is an integer
//        while (choice < 1 || choice > 7) {
//            cout << endl << "Please enter a number in the range 1-7: ";
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
//            case 6:
//                cout << "6." << endl << endl;
//                break;
//            case 7:
//                cout << "7." << endl << endl;
//                break;
//            //this should never be reached
//            default:
//                cout << "ERROR" << endl;
//                break;
//        }
//
//    } while (choice != 7);
//
//    return 0;
//}
