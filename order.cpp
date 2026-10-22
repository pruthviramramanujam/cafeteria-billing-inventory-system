#include "order.h"
#include "payment.h"
#include <iostream>
#include <cstddef>
using namespace std;
// Initialize static members
int Order::totalOrders = 0;
float Order::totalEarnings = 0;
Order::Order()
{
    totalAmount = 0;
    paymentMethod = nullptr;
    orderNo = totalOrders + 1;
}
Order::~Order()
{
    if (paymentMethod != nullptr)
    {
        delete paymentMethod;
        paymentMethod = nullptr;
    }
}
void Order::addItem(const Item& i, int q)
{
    orderItems.push_back(i);
    qty.push_back(q);
}
void Order::calculateTotal()
{
    totalAmount = 0;
    for (size_t i = 0; i < orderItems.size(); i++)
        totalAmount += orderItems[i].getPrice() * qty[i];
}
void Order::printBill(Inventory<Item>& inv)
{
    cout << "\n\tBILL\nOrder No: " << orderNo << "\n";
    if (orderItems.empty())
    {
        cout << "Order is empty." << endl;
        return;
    }
    for (size_t i = 0; i < orderItems.size(); i++)
    {
        cout << "- " << orderItems[i].getName()
             << " x" << qty[i]
             << " = Rs." << (orderItems[i].getPrice() * qty[i])
             << endl;
    }
    cout << "Total: Rs." << totalAmount << endl;
    string input;
    int ch;
    while (true)
    {
        cout << "\nPayment: 1. Cash  2. UPI\nChoice: ";
        cin >> input;
        // Check if input is "1" or "2"
        if (input == "1" || input == "2")
        {
            ch = stoi(input);
            break;
        }
        else
        {
            cout << "Invalid input. Enter 1 or 2 only.\n";
        }
    }
    if (ch == 1)
        paymentMethod = new CashPayment(totalAmount);
    else
        paymentMethod = new UpiPayment(totalAmount);
    // payment class handles own errors
    bool paysuccess = paymentMethod->makePayment();
    if (paysuccess)
    {
        totalOrders++;
        totalEarnings += totalAmount;

        for (size_t i = 0; i < orderItems.size(); i++)
        {
            inv.updateItemStock(orderItems[i].getID(), qty[i]);
        }
        cout << "\nPayment Successful. Order Confirmed." << endl;
    }
    else
    {
        cout << "\nPayment Failed. Order Canceled." << endl;
    }
}

void Order::showDailySummary()
{
    cout << "\n\tDAILY SUMMARY\n";
    cout << "------------------------" << endl;
    cout << "Total Orders: " << totalOrders << endl;
    cout << "Total Earnings: Rs." << totalEarnings << endl;
}