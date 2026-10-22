#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;
// Item Class
class Item
{
    int itemID;//unique id for each item
    string name;
    double price;
    int quantity;//Available Quantity
public:
    Item(int id = 0, string n = "", double p = 0, int q = 0);
    int getID() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void updateStock(int sold);//update quanity after item is sold
    void addStock(int added);//update quanity when the item is restocked 
    friend ostream& operator<<(ostream& out, const Item& i);
};
#endif