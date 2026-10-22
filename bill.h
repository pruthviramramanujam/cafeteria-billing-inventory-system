#ifndef BILL_H
#define BILL_H
#include "inventory.h"
#include "item.h"
#include <string>
using namespace std;
class BillingSystem
{
    Inventory<Item> inv;
public:
    void takeOrder();
    void addNewItem();
    void restockExistingItem();
    BillingSystem();
    void deleteExistingItem();
    void start();
};
#endif