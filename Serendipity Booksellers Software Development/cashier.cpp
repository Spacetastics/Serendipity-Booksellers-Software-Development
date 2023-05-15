//
//  cashier.cpp
//  Serendipity Booksellers Software Development
//
//  Created by Noah Cil on 4/29/23.
//

#include <iostream>
#include <iomanip>

using namespace std;

//int main() {
//    //getting sales data
//    cout << right << setw(26) << "Serendipity Booksellers" << endl;
//    cout << right << setw(21.5) << "Cashier Module" << endl << endl;
//    cout << "Date: ";
//    string date;
//    //assumes user will enter in MM//DD//YY format
////    cin >> date;
//    getline(cin, date);
//    cout << "Quantity of Book: ";
//    int quantity;
//    //assumes user will input a number
//    cin >> quantity;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore remaining input
//    cout << "ISBN: ";
//    string ISBN;
////    cin >> ISBN;
//    getline(cin, ISBN);
//    cout << "Title: ";
//    string title;
////    cin >> title;
//    getline(cin, title);
//    cout << "Price: ";
//    double price;
//    cin >> price;
//    cout << endl;
//
//    //calculations
//    double subtotal = price * quantity;
//    double tax = subtotal * 0.06;
//    double total = subtotal + tax;
//
//    //sales slip
////    cout << "Serendipity Book Sellers" << endl << endl;
////    cout << "Date: " + date << endl << endl;
////    cout << "Qty ISBN     Title          Price     Total" << endl;
////    cout << "-------------------------------------------" << endl << endl << endl;
////    cout << quantity << " " << ISBN << " " << title << " " << price << " " << subtotal;
////    cout << right << setw(18) << "Subtotal";
////    cout << left << setw(10) << subtotal;
////    cout << endl << right << setw(13) << "Tax";
////    cout << left << setw(10) << tax;
////    cout << endl << right << setw(15) << "Total";
////    cout << left << setw(10) << total << endl << endl;
////
////
////    cout << "Thank You for Shopping at Serendipity!" << endl;
//
//    cout << "Serendipity Book Sellers" << endl << endl;
//    cout << "Date: " << date << endl << endl;
//    cout << "Qty  ISBN           Title                               Price    Total    " << endl;
//    cout << "--------------------------------------------------------------------------" << endl;
//    cout << fixed << setprecision(2);
//    cout << left << setw(5) << quantity << setw(15) << ISBN << setw(36) << title << "$ " << setw(7) << price << "$ " << setw(7) << subtotal << endl << endl;
//    cout << right << setw(21) << "Subtotal" << setw(46) << "$ " << subtotal << endl;
//    cout << right << setw(16) << "Tax" << setw(52) << "$  " << tax << endl;
//    cout << right << setw(18) << "Total" << setw(49) << "$ " << total << endl << endl;
//
//    cout << "Thank You for Shopping at Serendipity!" << endl;
//
//    //since ISZBN is a standard size, and QTY is predictable and so is price, use stw to format within the line to give adequate spacing
//    //all ISBN numbers are 13 chars long
//    //34 is my longest title length
//    //three bottom lines start 14 spaces in
//    //66 spaces from start to last dollar sign
//}
