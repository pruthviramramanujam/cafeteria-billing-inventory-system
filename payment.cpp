#include "payment.h"
#include <string>
#include <iostream>
using namespace std;
Payment::Payment(float amt) 
{ 
    amount = amt; 
}
Payment::~Payment() {} 
CashPayment::CashPayment(float amt) : Payment(amt) {}
bool CashPayment::makePayment()
{
    string input;
    float cash;
    while (true)
    {
        cout << "Enter cash given: ";
        cin >> input;
        try
        {
            cash = stof(input);// if conversion fails then go to catch 
            if (cash < amount)
            {
                cout << "Insufficient amount. Need at least Rs." << amount << endl;
            }
            else
            {
                cout << "Change Returned: Rs." << cash - amount << "\n";
                return true;
            }
        }
        catch (...)
        {
            cout << "Invalid input. Please enter a numeric amount." << endl;
        }
    }
}
UpiPayment::UpiPayment(float amt) : Payment(amt) {}
bool UpiPayment::makePayment()
{
    string upi;
    while (true)
    {
        cout << "Enter UPI ID : ";
        cin >> upi;
        if (upi.length() < 5)
        {
            cout << "Invalid UPI ID format. Please try again." << endl;
        }
        else
        {
            cout << "Processing UPI payment Success" << endl;
            return true;
        }
    }
}