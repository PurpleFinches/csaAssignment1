// See my GitHub Repo for commit history.
//
// This was NOT written with ANY help from AI in ANY shape or form, neither for
// code completion nor for teaching. I haven't coded in C++ in about eight
// months, so I wanted to see how far I could get just on memory (and some of my
// old repo snippets) alone.

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

void helpDoc();
double standardizeUserNum(const std::string &, const std::string &, int);
double convertNumType(const std::string &, const std::string &, int);

int main() {
  std::string numType;
  std::string convertType;
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
      // Not prompting for input, skipping over. Something must already be in
      // the stream
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter the type of number you will be converting to: ";
      std::getline(std::cin, convertType);
      std::transform(convertType.begin(), convertType.end(),
                     convertType.begin(), ::toupper);
    }

    std::cout << "Converted Number: "
              << convertNumType(numType, convertType, userNum) << std::endl;
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

double standardizeUserNum(const std::string &numType,
                          const std::string &convertType, int userNum) {
  if ((numType == "D" || numType == "DEC") &&
      (convertType == "D" || convertType == "DEC")) {
    return userNum;
  } else {
  };
}

double convertNumType(const std::string &numType,
                      const std::string &convertType, int userNum) {
  double convertedVal = standardizeUserNum(numType, convertType, userNum);

  if (numType == "D" || numType == "DEC") {
    return convertedVal;
  } else if (numType == "B" || numType == "BIN") {
  } else if (numType == "H" || numType == "HEX") {
  } else if (numType == "F" || numType == "FLT") {
  } else {
    std::cout << "Invalid conversion." << std::endl;
    return 0;
  }
}
