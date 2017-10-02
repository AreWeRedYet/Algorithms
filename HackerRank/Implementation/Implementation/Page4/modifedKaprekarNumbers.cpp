#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> getNumberDigits(long long number) {
    vector<int> digits;
    
    if (number == 0) {
        return vector<int>(1, 0);
    }
    
    while (number > 0) {
        int digit = number % 10;
        number = number / 10;
        digits.push_back(digit);
    }
    
    reverse(digits.begin(), digits.end());
    
    return digits;
}

int getNumber(const vector<int>& digits) {
    int number = 0;
    for (int i = 0; i < digits.size(); i++) {
        number = 10*number + digits[i];
    }
    
    return number;
}

bool isKaprekarNumber(int number) {
    long long squareNumber = (long long)number * number;
    
    vector<int> numberDigits = getNumberDigits(number);
    vector<int> squareNumberDigits = getNumberDigits(squareNumber);
    
    unsigned long firstNumberSize = squareNumberDigits.size() % 2 == 0 ? numberDigits.size() : numberDigits.size() - 1;
    
    int number1 = getNumber(vector<int>(squareNumberDigits.begin(), squareNumberDigits.begin() + firstNumberSize));
    int number2 = getNumber(vector<int>(squareNumberDigits.begin() + firstNumberSize, squareNumberDigits.end()));
    
    return number1 + number2 == number;
}

vector<int> getKaprekarNumbers(int start, int end) {
    vector<int> kaprekarNumbers;
    
    for (int i = start; i <= end; i++) {
        if (isKaprekarNumber(i)) {
            kaprekarNumbers.push_back(i);
        }
    }
    
    return kaprekarNumbers;
}

int main()
{
    int start, end;
    
    cin >> start >> end;
    
    vector<int> kaprekarNumbers = getKaprekarNumbers(start, end);
    
    if (kaprekarNumbers.size() == 0) {
        cout << "INVALID RANGE" << endl;
    } else {
        for (int i = 0; i < kaprekarNumbers.size(); i++) {
            cout << kaprekarNumbers[i];
            
            if (i == kaprekarNumbers.size() - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    
    cout << endl;
    
    return 0;
}
