#include "item.h"
// Constructor
Item::Item(int id, string n, double p, int q)
{
    itemID = id;
    name = n;
    price = p;
    quantity = q;
}
int Item::getID() const 
{ 
    return itemID; 
}
string Item::getName() const
{ 
    return name; 
}
double Item::getPrice() const
{ 
    return price; 
}
int Item::getQuantity() const
{ 
    return quantity; 
}
void Item::addStock(int added)// Increase stock
{
    if (added > 0)
        quantity += added;
}
void Item::updateStock(int sold)// Reduce stock after sale
{
    if (quantity >= sold)
        quantity -= sold;
}
ostream& operator<<(ostream& out, const Item& i)
{
    out << "[" << i.itemID << "] " 
        << i.name << "  Rs." << i.price
        << " (Available: " << i.quantity << ")"; 
    return out;
}