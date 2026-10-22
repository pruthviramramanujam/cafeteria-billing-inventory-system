# Cafeteria Billing and Inventory System
A terminal-based cafeteria billing system developed in C++ as part of our Object-Oriented Programming course at IIITDM Kancheepuram.

The program handles menu management, customer orders, billing, payments, and inventory updates through a simple command-line interface.

## Features

- Display menu items with prices and available stock
- Place orders containing multiple items
- Calculate bills and process payments
- Accept cash payments and simulate UPI payments
- Add new items, restock items, and delete items
- Track total orders and earnings during a session
- Validate item quantities and prevent orders from exceeding available stock

## Technologies Used

- C++17
- Object-Oriented Programming
- STL (`vector`)
- C++ templates and operator overloading

## Project Structure

```
.
├── main.cpp
├── bill.h
├── bill.cpp
├── item.h
├── item.cpp
├── inventory.h
├── inventory.cpp
├── order.h
├── order.cpp
├── payment.h
├── payment.cpp
├── README.md
└── .gitignore
```

## How to Compile and Run
Make sure you have a C++ compiler such as `g++` installed.

Compile the project:

```
g++ -std=c++17 main.cpp item.cpp inventory.cpp order.cpp payment.cpp bill.cpp -o cafeteria
```
Run on Linux or macOS:

```
./cafeteria
```
On Windows with MinGW:

```
.\cafeteria.exe
```

## How to Use
When you start the program, a menu appears with the following options:

1. Show Menu
2. Take Order
3. Daily Summary
4. Add New Item
5. Restock Item
6. Delete Item
7. Exit
Follow the prompts in the terminal to manage inventory or place an order. During checkout, choose cash or UPI. UPI payments are simulated; the application does not connect to a real payment service.

## Concepts Used
This project helped us apply the following C++ concepts:

- Classes and objects
- Encapsulation and abstraction
- Inheritance and runtime polymorphism
- Templates
- Operator overloading
- Static data members
- Exception handling
- Dynamic memory management

## Team and Contributions
This project was developed by a team of three. We divided the implementation into separate modules and worked on integrating them into one application.

Team memberContributionsQamar Abbas Musvi`item.h`, `item.cpp`, `payment.h`, `payment.cpp` — item representation and payment classesPruthvi Ram`inventory.h`, `inventory.cpp`, `order.h`, `order.cpp` — inventory management and order processingValmiki Vinay`bill.h`, `bill.cpp`, `main.cpp` — billing system, application menu, and program entry pointAdditional responsibilities:

- Qamar Abbas — project report
- Pruthvi Ram — presentation

## Limitations

- Inventory and daily totals are stored in memory and reset when the program exits.
- UPI payment is a simulation, not a real transaction.
- The application runs entirely in the terminal; it has no graphical interface.

## What We Learned
Working on this project gave us practical experience with C++ class design, templates, inheritance, polymorphism, and integrating multiple source files into a working application.
