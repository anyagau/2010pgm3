//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: A program for the new ice cream place that will give you the menu and receipt based on what ice cream you order.
// Process: After you input a (viable) ice cream type (1-4), the program will assign your input to the proper ice cream and it's cost. 
// Following that, it will ask you for your desired cone type, excluding any results that aren't exactly what was offered. It will then tell 
// you what you've ordered, and give you what it will cost and ask for payment. If your payment isn't enough, it will ask for more until you
// have paid enough. It will then output a receipt outlining what you ordered, what you paid, and what your change is.
// Results: The ice cream cone you ordered, the cost of the cone, what you paid, and any change owed to you. 
//
// Class: CS2010
// Section: 100x
// Term: Fall 2024
// Author: Anya Gau
//
// Reflection: The new knowledge of for and while loops in this chapter helped make certain aspects easier, with the loops making it possible
// for the user to go back and fix any typos they made when trying to put in their inputs, instead of the system shutting down or glitching.
// The number of trivial mistakes I made on this code was less than before. 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
using namespace std;

//const variables
const double RockyMixture = 2.50;
const double StormyMixture = 3.25 ;
const double BlizzardMixture = 3.75;
const double SuperCellMixture = 4.25;

int main () {
// all other variables
string wafflecone;
string sugarcone;
string coneChoice;
string strIcecream;
double icecreamChoice;
double Payment;
double additionalPayment;

// This is the menu section, printing out the ice cream choices and prompting your for which ice cream you want
cout << setw(35) << setfill('-') << "" << endl;
cout << "1. Rocky" << setw(16) << setfill(' ') << right << "$2.50" << endl;
cout << "2. Stormy" << setw(15) << setfill(' ') << right << "$3.25" << endl;
cout << "3. Blizzard" << setw(13) << setfill(' ') << right << "$3.75" << endl;
cout << "4. SuperCell" << setw(12) << setfill(' ') << right << "$4.25" << endl;
cout << "5. Quit" << endl;
cout << setw(35) << setfill('-') << "" << endl;
cout << "Enter your choice of ice creams: ";
cin >> icecreamChoice; 

// If you put in a wrong number for ice cream choice, this will stop you
    while ((icecreamChoice > 5) || (icecreamChoice < 1)) {
        cout << "Invalid Choice, please re-enter! ";
        cin >> icecreamChoice;
    }

// Matching the ice cream types to the input
    if (icecreamChoice == 1) {
        icecreamChoice = RockyMixture;
        strIcecream = "Rocky";
    }
    else if (icecreamChoice == 2) {
        icecreamChoice = StormyMixture;
        strIcecream = "Stormy";
    }
    else if (icecreamChoice == 3) {
        icecreamChoice = BlizzardMixture;
        strIcecream = "Blizzard";
    }
    else if (icecreamChoice == 4) {
        icecreamChoice = SuperCellMixture;
        strIcecream = "SuperCell";
    }
    else if (icecreamChoice == 5) {
        cout << "Goodbye!";
        abort();
    }

// Determining the cone types
cout << setw(35) << setfill('-') << "" << endl;
cout << "Waffle" << endl;
cout << "Sugar" << endl;
cout << setw(35) << setfill('-') << "" << endl;
cout << "Enter your choice of cones: ";
cin >> coneChoice;

// This will exclude any cone type that isn't exactly "Waffle" or "Sugar"
    while ((coneChoice != "Waffle") && (coneChoice != "Sugar")) {
        cout << "Invalid Choice, please re-enter: ";
        cin >> coneChoice;
    }

// This section will tell you the final order and cost
cout << setw(35) << setfill('-') << "" << endl;
cout << "You have ordered a " << endl;
cout << coneChoice << " Cone " << strIcecream << " ice cream" << endl;
cout << "That will be $" << fixed << setprecision(2) << icecreamChoice << endl;
cout << setw(35) << setfill('-') << "" << endl;

// Determining how much you pay, as well as how much you will owe/be owed if under/over total
cout << "Enter the amount to pay: ";
cin >> Payment;
    while (Payment < icecreamChoice) {
        cout << "You still owe $" << icecreamChoice - Payment << endl;
        cout << "Enter additional payment: ";
        cin >> additionalPayment;
        Payment = Payment + additionalPayment;
    }
    cout << setw(35) << setfill('-') << "" << endl;
    cout << "Here is your:" << endl;
    cout << coneChoice << " Cone " << strIcecream << " ice cream!" << endl;
    cout << setfill(' ');
    cout << "Cost:" << right << setw(15) << "$" << fixed << setprecision(2) << icecreamChoice << endl;
    cout << "Paid:" << right << setw(15) << "$" << fixed << setprecision(2) << Payment << endl;
    cout << "Change Back:" << right << setw(8) << "$" << fixed << setprecision(2) << Payment - icecreamChoice << endl;
    cout << setw(35) << setfill('-') << "" << endl;

    return 0;
}