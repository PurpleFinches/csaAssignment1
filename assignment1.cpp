#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

void helpDoc();

int main() {
  std::string numType;
  int userNum;

  std::cout << "-------------------------------------------------------\n"
            << "This program takes a value (Decimal/Binary/Hex/Float) and\n"
            << "converts it to another value type of the user's choice.\n"
            << "For help, type \"help\" in any input box. 'x' to quit.\n"
            << "-------------------------------------------------------\n";

  while (true) {
    std::cout << "Enter the type of number you will be inputting: ";
    std::getline(std::cin, numType);
    std::transform(numType.begin(), numType.end(), numType.begin(), ::toupper);

    if (numType == "X") {
      break;
    } else if (numType == "HELP") {
      helpDoc();
      continue;
    } else {
      std::cout << "Enter a number: ";
      while (!(std::cin >> userNum)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Provide a valid number.\n";
        std::cout << "Enter a number: ";
      }
    }

    if (numType == "DEC" || numType == "D") {
      std::cout << "DEBUG: DEC\n";
    } else if (numType == "BIN" || numType == "B") {
      std::cout << "DEBUG: BIN\n";
    } else if (numType == "HEX" || numType == "H") {
      std::cout << "DEBUG: HEX\n";
    } else if (numType == "FLT" || numType == "F") {
      std::cout << "DEBUG: FLT\n";
    }

    return 0;
  }
}

void helpDoc() {
  std::cout
      << "-------------------------------------------------------\n"
      << "This converter takes a value and converts it to another\n"
      << "value type of the user's choice. Valid inputs for number "
         "type are:\n"
      << "Decimal: 'D' or 'DEC'\n"
      << "Binary: 'B' or 'BIN'\n"
      << "Hex: 'H' or 'HEX'\n"
      << "Float: 'F' or 'FLT'\n"
      << "Enter any one or three-character input when prompted for the number "
         "type.\n"
      << "-------------------------------------------------------\n";
}
