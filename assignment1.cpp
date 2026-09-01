#include <iostream>
#include <string>

int main() {
    std::string numType;
    int userNum;

    std::cout << "This program takes a value (Decimal/Binary/Hex/Float) and\n"
              << "converts it to another value type of the user's choice.\n"
              << "For help, type \"help\" in any input box.\n";

    while (0) {
        std::cout << "Enter the type of number you will be inputting: ";
        std::getline(std::cin, numType);

        if (numType == "help") {
            std::cout << "Returns the help doc.";
        }

        std::cout << "You entered: " << value << ".\n";
    }

    return 0;
}
