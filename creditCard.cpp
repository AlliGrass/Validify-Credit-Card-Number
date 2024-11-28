#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int MAX_SIZE = 20;
    int series[MAX_SIZE];
    int count = 0;
    
    cout << "Enter credit card number: " << endl;
    
    // read numbers 
    while (count < MAX_SIZE) {
        int num;
        cin >> num;
        
        if (num == -1)
            break;
        
        if (num >= 0 && num <= 9) {
            series[count] = num;
            count++;
        }
        else {
            cout << "Invalid input. Enter in one digit segments." << endl;
        }
    }
    
    // print the numbers
    cout << "\nCredit card number is: ";
    for (int i = 0; i < count; i++) {
        cout << series[i];
    }
    cout << endl;
    
    stringstream ss;
    for (int i = 0; i < count; i++) {
        ss << series[i];
    }
    string creditcardnumber = ss.str();
    
    int sum1 = 0;
    int sum2 = 0;

    // check sum
    cout << "Numbers for sum1 are: ";
    for (int i = creditcardnumber.length() - 2; i >= 0; i -= 2) {
        int digit = creditcardnumber[i] - '0';
        cout << digit << " ";
        int doubled = digit * 2;

        if (doubled > 9) {
            // Add the digits of the doubled number
            doubled = (doubled % 10) + (doubled / 10);
        }

        sum1 += doubled;
    }

    cout << "\nSum1 is " << sum1 << endl;

    // Perform sum calculation for other numbers
    cout << "Numbers for sum2 are: ";
    for (int i = creditcardnumber.length() - 3; i >= 0; i -= 2) {
        int digit = creditcardnumber[i] - '0';
        cout << digit << " ";
        sum2 += digit;
    }

    cout << "\nSum2 is " << sum2 << endl;

    // Calculate checksum and verify the credit card number
    int totalSum = sum1 + sum2;
    int checksum = (totalSum * 9) % 10;
    int lastdigit = creditcardnumber[creditcardnumber.length() - 1] - '0';

    cout << "Checksum is " << checksum << endl;
    cout << "Last digit on credit card is " << lastdigit << endl;

    cout << "Checksum " << checksum << " and last digit " << lastdigit << " are ";
    if (checksum == lastdigit) {
        cout << "the same: Valid credit card number." << endl;
    } else {
        cout << "not the same: Invalid credit card number." << endl;
    }

    return 0;
}
