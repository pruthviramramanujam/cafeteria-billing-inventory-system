#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "item.h"
#include "payment.h"
#include "inventory.h" // Include template header
using namespace std;
template<typename T>//forward-declare the template class as inventory is template class and we are using it in print bill
class Inventory;
class Order// Handles customer orders
{
    static int totalOrders;   // Total orders placed today
    static float totalEarnings; // Total Earning
    int orderNo;                // Order ID
    vector<Item> orderItems;    // Items in current order
    vector<int> qty;            // Quantity for each item
    float totalAmount;          // Final bill amount
    Payment *paymentMethod;     // Payment handler (Cash/UPI)

public:
    Order();
    void addItem(const Item& i, int q); // Add item to order
    void calculateTotal(); // Compute totalAmount
    void printBill(Inventory<Item> &inv);// takes the specific Inventory<Item>
    static void showDailySummary(); // Day-end summary
    ~Order(); // Cleanup paymentMethod
};

#endif