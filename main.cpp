#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace {

bool readText(const std::string& prompt, std::string& value) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, value)) {
            return false;
        }

        if (value.find_first_not_of(" \t\r\n") != std::string::npos) {
            return true;
        }
        std::cout << "Please enter a value.\n";
    }
}

bool readNumber(const std::string& prompt, double minimum, double& value) {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) {
            return false;
        }

        std::istringstream input(line);
        char extra = '\0';
        if ((input >> value) && !(input >> extra) && std::isfinite(value) &&
            value >= minimum) {
            return true;
        }
        std::cout << "Please enter a number";
        if (minimum > 0.0) {
            std::cout << " greater than zero";
        } else {
            std::cout << " of zero or more";
        }
        std::cout << ".\n";
    }
}

bool readMenuChoice(int& choice) {
    while (true) {
        std::cout << "\nSelect an option: ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            return false;
        }

        std::istringstream input(line);
        char extra = '\0';
        if ((input >> choice) && !(input >> extra) && choice >= 1 && choice <= 3) {
            return true;
        }
        std::cout << "Choose 1, 2, or 3.\n";
    }
}

std::string quantityText(double value) {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2) << value;
    std::string text = output.str();
    while (!text.empty() && text[text.size() - 1] == '0') {
        text.erase(text.size() - 1);
    }
    if (!text.empty() && text[text.size() - 1] == '.') {
        text.erase(text.size() - 1);
    }
    return text;
}

void checkStockAvailability() {
    std::string riceType;
    double availableStock = 0.0;
    double requiredStock = 0.0;

    if (!readText("Enter rice type: ", riceType) ||
        !readNumber("Enter available stock (in kg): ", 0.0, availableStock) ||
        !readNumber("Enter required stock (in kg): ", 0.000000000001, requiredStock)) {
        return;
    }

    std::cout << "\n--- Stock Availability Details ---\n"
              << "Rice Type: " << riceType << '\n'
              << "Available Stock: " << quantityText(availableStock) << " kg\n"
              << "Required Stock: " << quantityText(requiredStock) << " kg\n";

    if (availableStock >= requiredStock) {
        std::cout << "Status: Stock Available\n"
                  << "Remaining Stock: "
                  << quantityText(availableStock - requiredStock) << " kg\n";
    } else {
        std::cout << "Status: Insufficient Stock\n"
                  << "Additional Quantity Needed: "
                  << quantityText(requiredStock - availableStock) << " kg\n";
    }
}

void generateBill() {
    std::string riceType;
    double quantity = 0.0;
    double pricePerKg = 0.0;

    if (!readText("Enter rice variety: ", riceType) ||
        !readNumber("Enter quantity (in kg): ", 0.000000000001, quantity) ||
        !readNumber("Enter price per kg (Rs.): ", 0.000000000001, pricePerKg)) {
        return;
    }

    const double total = quantity * pricePerKg;
    if (!std::isfinite(total)) {
        std::cout << "The bill amount is too large to calculate.\n";
        return;
    }

    const std::string rupee = "\xE2\x82\xB9";
    std::cout << "\n"
              << "============================================\n"
              << "                 RICE BILL\n"
              << "============================================\n"
              << std::left << std::setw(22) << "Rice variety" << riceType << '\n'
              << std::setw(22) << "Quantity" << quantityText(quantity) << " kg\n"
              << std::setw(22) << "Price per kg" << rupee << ' '
              << std::fixed << std::setprecision(2) << pricePerKg << '\n'
              << "--------------------------------------------\n"
              << std::setw(22) << "Total amount" << rupee << ' ' << total << '\n'
              << "============================================\n";
}

void printMenu() {
    std::cout << "\n=== RICE BUSINESS MANAGEMENT SYSTEM ===\n"
              << "1. Check Stock Availability\n"
              << "2. Generate Bill\n"
              << "3. Exit\n";
}

}  // namespace

int main() {
    bool running = true;
    while (running) {
        printMenu();
        int choice = 0;
        if (!readMenuChoice(choice)) {
            break;
        }

        switch (choice) {
            case 1:
                checkStockAvailability();
                break;
            case 2:
                generateBill();
                break;
            case 3:
                running = false;
                std::cout << "Goodbye.\n";
                break;
        }
    }

    return 0;
}
