#include "bill.h"
#include "order.h"
#include <iostream>
#include <string>
#include<limits>
#include <sstream>
#include <unordered_map>
using namespace std;

namespace
{
bool readInt(const string& prompt, int& value)
{
    while (true)
    {
        cout << prompt;
        string input;
        if (!(cin >> input))
            return false;

        istringstream inputStream(input);
        int parsedValue;
        char extra;
        if ((inputStream >> parsedValue) && !(inputStream >> extra))
        {
            value = parsedValue;
            return true;
        }

        if (cin.eof())
            return false;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer.\n";
    }
}

bool readDouble(const string& prompt, double& value)
{
    while (true)
    {
        cout << prompt;
        string input;
        if (!(cin >> input))
            return false;

        istringstream inputStream(input);
        char extra;
        if ((inputStream >> value) && !(inputStream >> extra) && value >= 0)
            return true;

        if (cin.eof())
            return false;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative price.\n";
    }
}
}

BillingSystem::BillingSystem()
{
    inv += Item(101, "Burger", 80, 20);
    inv += Item(102, "Pizza", 150, 10);
    inv += Item(103, "Fries", 60, 15);
    inv += Item(104, "Coke", 40, 30);
}
void BillingSystem::addNewItem()
{
    cout << "\n\tAdd New Item\n";
    int id, q;
    string n;
    double p;
    if (!readInt("Enter new Item ID: ", id))
        return;
    //Item* it = inv.getItemByID(id);
    if (inv.getItemByID(id) != nullptr)
    {
        cout << "Error: Item ID " << id << " already exists.\n";
        return;
    }
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, n);
    if (!readDouble("Enter price: ", p))
        return;
    if (!readInt("Enter initial stock: ", q))
        return;
    inv += Item(id, n, p, q);
    cout << "Item added successfully.\n";
}
void BillingSystem::restockExistingItem()
{
    cout << "\n\tRestock Item\n";
    inv.showMenu();
    int id, q;
    if (!readInt("\nEnter Item ID to restock: ", id))
        return;
    Item* it = inv.getItemByID(id);
    if (it == nullptr)
    {
        cout << "Error: Item ID not found.\n";
        return;
    }
    if (!readInt("Enter quantity to add: ", q))
        return;
    inv.restockItem(id, q);
    cout << "Stock updated.\n";
}
void BillingSystem::takeOrder()
{
    cout << "\n\tTake Order\n";
    inv.showMenu();
    Order o;
    unordered_map<int, int> selectedQty;
    int id, q;
    while (true)
    {
        if (!readInt("\nEnter Item ID (0 to finish): ", id))
            return;
        if (id == 0)
            break;
       Item* it = inv.getItemByID(id);

if (it == nullptr)
{
    cout << "Invalid ID!\n";
    continue;
}

if (!readInt("Enter quantity: ", q))
    return;

if (q <= 0)
{
    cout << "Invalid quantity.\n";
    continue;
}

int alreadySelected = selectedQty[id];
int remaining = it->getQuantity() - alreadySelected;

if (q > remaining)
{
    cout << "Not enough stock! Available: "
         << remaining << "\n";
    continue;
}

selectedQty[id] += q;
o.addItem(*it, q);

cout << "Selected: " << *it << endl;
    }
    o.calculateTotal();
    o.printBill(inv);
}
void BillingSystem::deleteExistingItem()
{
    cout << "\n\tDelete Item\n";
    inv.showMenu();
    int x;
    if (!readInt("\nEnter Item ID to delete: ", x))
        return;
    try
    {
        inv.deleteItem(x);
    }
    catch (const std::runtime_error& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "An unexpected error occurred while deleting." << endl;
    }
}
void BillingSystem::start()
{
    while (true)
    {
        cout << "\n\n\tCAFETERIA BILLING SYSTEM\n";
        cout << "1. Show Menu\n";
        cout << "2. Take Order\n";
        cout << "3. Daily Summary\n";
        cout << "4. Add New Item\n";
        cout << "5. Restock Item\n";
        cout << "6. Delete Item\n";
        cout << "7.Exit\n";
        int ch;
        if (!readInt("Choice: ", ch))
            return;
        switch (ch)
        {
            case 1: 
                inv.showMenu(); 
                break;
            case 2: 
                takeOrder(); 
                break;
            case 3: 
                Order::showDailySummary(); 
                break;
            case 4: 
                addNewItem(); 
                break;
            case 5: 
                restockExistingItem(); 
                break;
            case 6: 
                deleteExistingItem(); 
                break;
            case 7: 
                exit(0);
                break;
            default: 
                cout << "Invalid choice.\n";
        }
    }
}
