// See my GitHub Repo for commit history.
//
// This was NOT written with ANY help from AI in ANY shape or form, neither for
// code completion nor for teaching. I haven't coded in C++ in about eight
// months, so I wanted to see how far I could get just on memory (and some of my
// old repo snippets) alone. I did use some online resources like Stack
// Overflow.
//
// I decided the easiest way to do this would be to first convert the user's
// input to decimal, then convert the decimal number to whatever format they
// wanted. My first idea was to use four separate functions (convertToDec,
// convertToBin, etc.) that did checks for the user's input type, but realized
// that I'd be writing four near-identical if-else statements. This felt like
// the cleaner route.

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

void helpDoc();
double standardizeUserNum(const std::string &, const std::string &, double);
std::string convertNumType(const std::string &, const std::string &, double);

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
  std::cout << "-------------------------------------------------------\n"
            << "This converter takes a value and converts it to another\n"
            << "value type of the user's choice. Valid inputs for number "
               "type are:\n"
            << "Decimal: 'D' or 'DEC'\n"
            << "Binary: 'B' or 'BIN'\n"
            << "Hex: 'H' or 'HEX'\n"
            << "Enter any one or three-character input when prompted\n"
            << "for the number type.\n"
            << "-------------------------------------------------------\n";
}

double standardizeUserNum(const std::string &numType, double userNum) {
  // If user's input is decimal, then just return the same number and move on.
  if (numType == "D" || numType == "DEC") {
    return userNum;
    //
  } else if (numType == "B" || numType == "BIN") {
    int decVal = 0;
    int baseVal = 1;

    for (int i = std::to_string(userNum).length() - 1; i >= 0; i--) {
      if (std::to_string(userNum)[i] == '1') {
        decVal += baseVal;
      }
    }

    return decVal;
  } else if (numType == "H" || numType == "HEX") {
    return 0;
  } else {
    std::cout << "Invalid Conversion." << std::endl;
    return 0;
  }
}

std::string convertNumType(const std::string &numType,
                           const std::string &convertType, double userNum) {
  int convertedVal = standardizeUserNum(numType, userNum);

  // Converts everything to strings for the return. If value is 0, then it
  // returns 0.
  if (convertType == "D" || convertType == "DEC") {
    return std::to_string(convertedVal);
  } else if (convertType == "B" || convertType == "BIN") {
    if (numType == "B" || numType == "BIN") {
      return std::to_string((int)userNum);
    } else if (convertedVal == 0) {
      return std::to_string(0);
    } else {

      int binArr[32];
      std::string binVal;
      int i = 0;

      // After initializing an array, we devide the user input by 2 and add it
      // to an array of binArr. The remainder is stored, then the user input is
      // divided by 2 until the convertedVal equals 0.
      while (convertedVal > 0) {
        binArr[i] = convertedVal % 2;
        convertedVal /= 2;
        i++;
      }

      // Stores the values calcualted from the while loop in reverse order
      for (int j = i - 1; j >= 0; j--) {
        binVal += std::to_string(binArr[j]);
      }

      return binVal;
    }

  } else if (convertType == "H" || convertType == "HEX") {
    if (numType == "H" || numType == "HEX") {
      return std::to_string(userNum);
    } else if (convertedVal == 0) {
      return std::to_string(0);
    } else {
      return "ok";
    }
  } else {
    std::cout << "Invalid conversion." << std::endl;
    return "ERROR";
  }
}
