#include "inventory.h"
#include "item.h"
#include <iostream>
#include <cstddef>
using namespace std;
template <typename T>
void Inventory<T>::showMenu()
{
    cout << "\n\tMENU\n";
    if (stock.empty())
    {
        cout << "Inventory is empty." << endl;
        return;
    }
    for (size_t i = 0; i < stock.size(); i++)
    {
        cout << stock[i] << endl;
    }
}
template <typename T>
T* Inventory<T>::getItemByName(string name)
{
    for (size_t i = 0; i < stock.size(); i++)
    {
        if (stock[i].getName() == name)
        {
            return &stock[i];
        }
    }
    return nullptr;
}

template <typename T>
T* Inventory<T>::getItemByID(int id)
{
    for (size_t i= 0; i < stock.size(); i++)
    {
        if (stock[i].getID() == id)
        {
            return &stock[i];
        }
    }
    return nullptr;
}
template <typename T>
void Inventory<T>::updateItemStock(int id, int qty)
{
    T* item = getItemByID(id);
    if (item != nullptr)
    {
        item->updateStock(qty);
    }
}
template <typename T>
void Inventory<T>::restockItem(int id, int qty)
{
    T* item = getItemByID(id);
    if (item != nullptr)
    {
        item->addStock(qty);
        cout << "Stock added successfully." << endl;
    }
    else
    {
        cout << "Error: Item ID " << id << " not found." << endl;
    }
}
template <typename T>
void Inventory<T>::deleteItem(int id)
{
    //iterate to find and delete
    for (size_t i = 0; i < stock.size(); i++)
    {
        if (stock[i].getID() == id)
        {
            stock.erase(stock.begin() + i); // Delete
            cout << "Item deleted successfully." << endl;
            return; // Exit immediately after deleting
        }
    }
    throw std::runtime_error("Error: Item ID not found. Cannot delete.");
}
template <typename T>
Inventory<T>& Inventory<T>::operator+=(const T& i)
{
    stock.push_back(i);
    return *this;
}
// EXPLICIT INSTANTIATION:
template class Inventory<Item>;