#include <iostream>
#include <cmath>
using namespace std;

int reverseDigits(int number) {
    int reversedNumber = 0;
    
    while (number > 0) {
        int lastDigit = number % 10;
        number = number / 10;
        reversedNumber = 10*reversedNumber + lastDigit;
    }
    
    return reversedNumber;
}

int beautifulDays(int startDay, int endDay, int k) {
    int beautifulCount = 0;
    
    for (int day = startDay; day <= endDay; day++) {
        if (abs(day - reverseDigits(day)) % k == 0) {
            beautifulCount++;
        }
    }
    
    return beautifulCount;
}

int main() {
    int i, j, k;
    
    cin >> i >> j >> k;
    
    cout << beautifulDays(i, j, k) << endl;
    
    return 0;
}
