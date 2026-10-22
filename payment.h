#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
using namespace std;
// Base class for all payment types
class Payment
{
protected:
    float amount;// Amount to be paid
public:
    Payment(float amt=0);
    virtual bool makePayment() = 0; // Pure virtual
    virtual ~Payment(); // Virtual destructor
};
class CashPayment : public Payment
{
public:
    CashPayment(float amt=0);
    bool makePayment() override; // Handle cash payment
};
class UpiPayment : public Payment
{
public:
    UpiPayment(float amt=0);
    bool makePayment() override;// Handle UPI payment
};
#endif