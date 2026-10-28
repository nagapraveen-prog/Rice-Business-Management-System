<<<<<<< HEAD
# Rice Business Management System

A simple, menu-driven C++ console program with two basic features: checking rice stock availability and calculating a rice bill.

## Features

- Enter a rice variety, the available stock, and the required quantity to see remaining stock.
- If stock is insufficient, see how many additional kilograms are needed.
- Enter a rice variety, quantity, and price per kilogram to calculate a clearly formatted bill in rupees.
- Reject invalid quantities, prices, and menu choices.

## Compile and run

Use a C++11-or-later compiler. In the project folder, open the VS Code terminal or another terminal.

### Windows

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o rice_business.exe
.\rice_business.exe
```

### Linux or macOS

```sh
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o rice_business
./rice_business
```

## Example stock check

```text
Enter rice type: Basmati Rice
Enter available stock (in kg): 500
Enter required stock (in kg): 200

--- Stock Availability Details ---
Rice Type: Basmati Rice
Available Stock: 500 kg
Required Stock: 200 kg
Status: Stock Available
Remaining Stock: 300 kg
```

## Example bill

For Sona Masoori, 10 kg at Rs. 55.00 per kg, the bill total is ₹550.00.
=======
# Rice-Business-Management-System
A C++ OOP-based Rice Business Management System using CSV file handling.
>>>>>>> 94144b6ac3c9b43fb01d6970019dc2a0aa797853
