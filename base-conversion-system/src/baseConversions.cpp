#include <iostream>
#include <cmath>
#include <cstring>
#include <limits> // For std::cin.ignore()
using namespace std;

// Function to display hidden credit message
void showCredits() {
    cout << "=============================" << endl;
    cout << "Developed by Dev @ AlphaTech" << endl;
    cout << "=============================" << endl;
}

// Function to wait for key press
void waitForKeyPress() {
    cout << "\nPress 'q' to quit or any other key to continue...";
    char key;
    cin >> key;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    if (key == 'q' || key == 'Q') {
        cout << "\nThank you for using the converter. Goodbye!" << endl;
        exit(0); // Exit the program
    }
}

// Main function to handle conversions between number systems
int main() {
    // Call hidden credit function
    showCredits();

    while (true) {
        int baseInput, baseOutput, number, temp, index;
        char hexInput[50], hexOutput[50];
        int converted[50], result = 0;

        cout << "\nNumber System Bases:" << endl;
        cout << "1. Decimal (Base 10)" << endl;
        cout << "2. Binary (Base 2)" << endl;
        cout << "3. Octal (Base 8)" << endl;
        cout << "4. Hexadecimal (Base 16)" << endl;

        cout << "\nEnter the base of your number system: ";
        cin >> baseInput;
        cout << "Enter the base of the desired number system: ";
        cin >> baseOutput;

        // Decimal (Base 10) conversions
        if (baseInput == 10) {
            cout << "Enter the number: ";
            cin >> number;

            if (baseOutput == 2) {
                cout << "Binary Conversion: ";
                index = 0;
                while (number > 0) {
                    converted[index++] = number % 2;
                    number /= 2;
                }
                for (int i = index - 1; i >= 0; i--) {
                    cout << converted[i];
                }
            } else if (baseOutput == 8) {
                cout << "Octal Conversion: ";
                index = 0;
                while (number > 0) {
                    converted[index++] = number % 8;
                    number /= 8;
                }
                for (int i = index - 1; i >= 0; i--) {
                    cout << converted[i];
                }
            } else if (baseOutput == 16) {
                cout << "Hexadecimal Conversion: ";
                index = 0;
                while (number > 0) {
                    temp = number % 16;
                    hexOutput[index++] = (temp < 10) ? temp + '0' : temp + 'A' - 10;
                    number /= 16;
                }
                for (int i = index - 1; i >= 0; i--) {
                    cout << hexOutput[i];
                }
            } else {
                cout << "Invalid Output Base!" << endl;
            }
        }

        // Binary (Base 2) to Decimal (Base 10)
        else if (baseInput == 2 && baseOutput == 10) {
            cout << "Enter the binary number: ";
            cin >> number;
            index = 0;
            while (number > 0) {
                temp = number % 10;
                result += temp * pow(2, index++);
                number /= 10;
            }
            cout << "Decimal Conversion: " << result;
        }

        // Octal (Base 8) to Decimal (Base 10)
        else if (baseInput == 8 && baseOutput == 10) {
            cout << "Enter the octal number: ";
            cin >> number;
            index = 0;
            while (number > 0) {
                temp = number % 10;
                result += temp * pow(8, index++);
                number /= 10;
            }
            cout << "Decimal Conversion: " << result;
        }

        // Hexadecimal (Base 16) to Decimal (Base 10)
        else if (baseInput == 16 && baseOutput == 10) {
            cout << "Enter the hexadecimal number: ";
            cin >> hexInput;
            int len = strlen(hexInput);
            index = 0;
            for (int i = len - 1; i >= 0; i--) {
                if (hexInput[i] >= '0' && hexInput[i] <= '9') {
                    temp = hexInput[i] - '0';
                } else if (hexInput[i] >= 'A' && hexInput[i] <= 'F') {
                    temp = hexInput[i] - 'A' + 10;
                } else {
                    cout << "Invalid Hexadecimal Digit!" << endl;
                    return 1;
                }
                result += temp * pow(16, index++);
            }
            cout << "Decimal Conversion: " << result;
        }

        else {
            cout << "Invalid Base Conversion!" << endl;
        }

        // Wait for user input before continuing
        waitForKeyPress();
    }

    return 0;
}
