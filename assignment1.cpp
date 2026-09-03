// This was NOT written with ANY help from AI in ANY shape or form, neither for
// code completion nor for teaching. I don't code often so I wanted to see how
// far I could get just on memory (and some of my old repo snippets) alone. I
// used some online resources like Stack Overflow and GFG for the
// conversion help.

// I decided the easiest way to do this would be to first convert the user's
// input to decimal, then convert the decimal number to whatever format they
// wanted. My first idea was to use four separate functions (convertToDec,
// convertToBin, etc.) that did checks for the user's input type, but realized
// that I'd be writing four near-identical if-else statements. This felt like
// the cleaner route. I'm not sure if it was.

// TO DO:
// Float Functionality (Float to Binary)

#include <algorithm>
#include <iostream>
#include <string>

void helpDoc();
double standardizeUserNum(const std::string &, const std::string &,
                          std::string &);
std::string convertNumType(const std::string &, const std::string &,
                           std::string &);

int main() {
    std::string numType;
    std::string convertType;
    std::string userNum;

    std::cout << "-------------------------------------------------------\n"
              << "This program takes a value (Decimal/Binary/Hex/Float) and\n"
              << "converts it to another value type of the user's choice.\n"
              << "For help, type \"help\" in any input box. 'x' to quit.\n"
              << "-------------------------------------------------------\n";

    while (true) {
        std::cout << "Enter the type of number you will be inputting: ";
        std::getline(std::cin, numType);
        std::transform(numType.begin(), numType.end(), numType.begin(),
                       ::toupper);

        if (numType == "X") {
            break;
        } else if (numType == "HELP") {
            helpDoc();
            continue;
        } else {
            std::cout << "Enter a value: ";
            std::getline(std::cin, userNum);
            std::transform(userNum.begin(), userNum.end(), userNum.begin(),
                           ::toupper);
        }

        std::cout << "Enter the type of number you will be converting to: ";
        std::getline(std::cin, convertType);
        std::transform(convertType.begin(), convertType.end(),
                       convertType.begin(), ::toupper);

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

// this function converts all input from the user into DECIMAL to then simplify
// conversion to another type later on.
std::string standardizeUserNum(const std::string &numType,
                               std::string &userNum) {
    // If user's input is decimal, then just return the same number and move on.
    if (numType == "D" || numType == "DEC") {
        return userNum;
        // If user's input is binary, then convert to decimal.
    } else if (numType == "B" || numType == "BIN") {
        if (userNum == "0") {
            return userNum;
        }

        // Conversion from binary to decimal works by starting from the furthest
        // right digit, then adding the base to the decVal if the digit is 1.
        // The base is doubled for the next position and so on until the decimal
        // value is formed. It is essentially just multiplying the bases the
        // same way you would on paper, where 1001 would be 1 + 0 + 0 + 8 = 9.
        // By multiplying each base by 2, you can then decide whether that next
        // base needs to be added.
        std::string binaryVal = userNum;
        int decVal = 0;
        int base = 1;

        for (int i = binaryVal.length() - 1; i >= 0; i--) {
            if (binaryVal[i] == '1') {
                decVal += base;
            }
            base *= 2;
        }

        return std::to_string(decVal);
        // Conversion from Hexadecimal to decimal works by first checking each
        // value from right-to-left. At the first (rightmost) value, the
        // character is converted into a digit. For values 0-9, it's converted
        // from a string to integer format. If the character is a value A - F,
        // it is converted into a value between 10 - 15. The digit is then
        // multiplied by the base and added to the decimal value, and the base
        // is multiplied by 16 before doing the same operations on the next
        // value. (This is the same as it normally works on paper, where you
        // multiply each digit by 16 raised to the power of its position.)
    } else if (numType == "H" || numType == "HEX") {
        int decVal = 0;
        int base = 1;
        std::string hexVal = userNum;

        for (int i = hexVal.length() - 1; i >= 0; i--) {
            int digit;

            if (hexVal[i] >= '0' && hexVal[i] <= '9') {
                digit = hexVal[i] - '0';
            } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
                digit = hexVal[i] - 'A' + 10;
            } else {
                continue;
            }

            decVal += digit * base;
            base *= 16;
        }

        return std::to_string(decVal);
    } else {
        return "INVALID CONVERSION. Type 'help' to see valid type inputs.";
    }
}

// This is the second step of conversion. Once the initial number is converted
// to decimal, this function will convert it into the desired value.
std::string convertNumType(const std::string &numType,
                           const std::string &convertType,
                           std::string &userNum) {

    std::string convertedVal = standardizeUserNum(numType, userNum);
    int convertedIntVal = std::stoi(convertedVal);
    double convertedDblVal = std::stod(convertedVal);

    // Decimals are not converted and instead returned in-place.
    if (convertType == "D" || convertType == "DEC") {
        return convertedVal;
        // Binary conversion. If Binary -> Binary or equal to 0, then it is not
        // converted and instead returned directly from user input.
    } else if (convertType == "B" || convertType == "BIN") {
        if (numType == "B" || numType == "BIN") {
            return userNum;
        } else if (convertedDblVal == 0.0) {
            return std::to_string(0);
        } else {
            std::string binVal;
            int binArr[32];
            int fracArr[32];
            double fracValInt;
            int i = 0;
            int k = 0;

            // Separate everything before and after the decimal
            size_t pos = convertedVal.find('.');
            std::string baseVal = convertedVal.substr(0, pos);
            std::string fracVal;

            if (pos == std::string::npos) {
                fracVal = "";
                fracValInt = 0;
            } else {
                fracVal = "0." + convertedVal.substr(pos + 1);
                fracValInt = std::stod(fracVal);
            }

            int baseValInt = baseVal.empty() ? 0 : std::stoi(baseVal);
            // After initializing an array, we divide the user input by 2 and
            // add it to an array of binArr. The remainder is stored, then the
            // user input is divided by 2 until the convertedVal equals 0.
            while (baseValInt > 0) {
                binArr[i] = baseValInt % 2;
                baseValInt /= 2;
                i++;
            }

            // Stores the values calculated from the while loop in reverse
            // order.
            for (int j = i - 1; j >= 0; j--) {
                binVal += std::to_string(binArr[j]);
            }

            if (fracValInt == 0) {
                fracVal = " ";
            } else {
                while (fracValInt != 0 && k < 16) {
                    fracValInt *= 2.0;
                    if (fracValInt >= 1) {
                        fracArr[k] = 1;
                        fracValInt -= 1;
                    } else {
                        fracArr[k] = 0;
                    }
                    k++;
                }

                fracVal.clear();
                for (int j = 0; j < k; j++) {
                    fracVal += std::to_string(fracArr[j]);
                }
            }

            std::string finalVal;
            if (fracVal == " ") {
                finalVal = binVal;
            } else {
                finalVal = binVal + '.' + fracVal;
            }
            return finalVal;
        }

        // Hex has the same initial logic as previous functions.
    } else if (convertType == "H" || convertType == "HEX") {
        size_t pos = convertedVal.find('.');
        std::string fracVal = '.' + convertedVal.substr(pos + 1);

        if (pos == std::string::npos) {
            fracVal = "0";
        }

        if (numType == "H" || numType == "HEX") {
            return userNum;
        } else if (convertedIntVal == 0) {
            return std::to_string(0);
        } else if (std::stod(fracVal) > 0) {
            return "ERROR: Floats CANNOT be converted to Hex.\n";
        } else {
            char hexDecVal[100];
            std::string hexVal;
            int i = 0;

            // While our user number is greater than 0, the userNum is
            // divided by 16 and the remainder converted into a
            // corresponding hex character. If the remainder is greater than
            // 10, as in 156 % 16 = 12, then 12 - 10 is added to the value
            // 'A' to create the second value of 156's hex code, C. In the
            // second value, the remainder is now less than 10 (9), so it is
            // added to 0 to get the second value. Since these values are in
            // reverse order, though, a for-loop exists at the end to
            // reverse the values (9C), then return them.
            while (convertedIntVal != 0) {
                int rem = convertedIntVal % 16;

                if (rem < 10) {
                    hexDecVal[i] = '0' + rem;
                } else {
                    hexDecVal[i] = 'A' + (rem - 10);
                }
                i++;
                convertedIntVal /= 16;
            }

            for (int j = i - 1; j >= 0; j--) {
                hexVal += hexDecVal[j];
            }
            return hexVal;
        }
    } else {
        std::cout << "Invalid conversion." << std::endl;
        return "ERROR";
    }
}
