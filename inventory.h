#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//template DECLARATION
template <typename T>
class Inventory
{
    vector<T> stock;
public:
    void showMenu();
    T* getItemByName(string name);
    T* getItemByID(int id);
    void updateItemStock(int id, int qty);
    void restockItem(int id, int qty);
    void deleteItem(int id);
    Inventory<T>& operator+=(const T& i);
};
#endif