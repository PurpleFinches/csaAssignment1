#include <algorithm>
#include <iostream>
#include <string>

void helpDoc();

int main() {
    std::string numType;
    int userNum;

    std::cout << "-------------------------------------------------------\n"
              << "This program takes a value (Decimal/Binary/Hex/Float) and\n"
              << "converts it to another value type of the user's choice.\n"
              << "For help, type \"help\" in any input box.\n"
              << "-------------------------------------------------------\n";

    while (1) {
        std::cout << "Enter the type of number you will be inputting: ";
        std::getline(std::cin, numType);
        std::transform(numType.begin(), numType.end(), numType.begin(),
                       ::toupper);

        std::cout << "value: " << numType << "\n";

        if (numType == "help") {
            helpDoc();
        } else {
            std::cout << "Enter a number: ";
            std::cin >> userNum;
            std::cout << "\nDEBUG: You entered " << userNum << ".";
        };

        if (numType == "DEC") {

        } else if (numType == "BIN") {
            std::cout << "DEBUG: BIN\n";
        } else if (numType == "HEX") {
            std::cout << "DEBUG: HEX\n";
        } else if (numType == "FLT") {
            std::cout << "DEBUG: FLT\n";
        }

        return 0;
    }
}

void helpDoc() {
    std::cout << "-------------------------------------------------------\n"
              << "This converter takes a value and converts it to another\n"
              << "value type of the user's choice. Valid inputs for number "
                 "type are:\n"
              << "Decimal: 'DEC'\n"
              << "Binary: 'BIN'\n"
              << "Hex: 'HEX'\n"
              << "Float: 'FLT'\n"
              << "Enter any three-character input when prompted for the number "
                 "type.\n"
              << "-------------------------------------------------------\n";
}
