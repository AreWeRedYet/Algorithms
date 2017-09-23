#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

// Big Integer for positive numbers
class BigInteger {
public:
    string value;
    
    BigInteger() {
        value = "0";
    }
    
    BigInteger(int value) {
        this->value = to_string(value);
    }
    
    BigInteger(string value): value(value)
    {}
    
    BigInteger operator + (const BigInteger &b) const {
        return BigInteger(sum(this->value, b.value));
    }
    
    BigInteger operator * (const BigInteger &b) const {
        return BigInteger(product(this->value, b.value));
    }
    
    BigInteger& operator *= (const BigInteger& b) {
        (*this) = (*this) * b;
        
        return *this;
    }
    
    friend ostream& operator << (ostream& out, BigInteger const& x);
    
private:
    string sum(const string &x, const string &y) const {
        unsigned long maxLength = max(x.length(), y.length());
        
        string result;
        
        int overflow = 0;
        for (int i = 0; i < maxLength; i++) {
            int xi = (int)x.length() - 1 - i;
            int yi = (int)y.length() - 1 - i;
            
            int digitX = xi >= 0 ? x[xi] - '0' : 0;
            int digitY = yi >= 0 ? y[yi] - '0' : 0;
            
            char digitSum = (digitX + digitY + overflow) % 10 + '0';
            overflow = (digitX + digitY + overflow) / 10;
            
            result.push_back(digitSum);
        }
        
        if (overflow != 0) {
            result.push_back(overflow + '0');
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    string multiplyByDigit(const string &x, int digit) const {
        if (digit > 9 || digit < 0) {
            throw "Not a digit";
        }
        
        if (digit == 0) {
            return "0";
        }
        
        int overflow = 0;
        string result;
        
        for (int i = 0; i < x.length(); i++) {
            int xi = (int)x.length() - i - 1;
            
            int digitX = x[xi] - '0';
            char digitSum = (digitX * digit + overflow) % 10 + '0';
            overflow = (digitX * digit + overflow) / 10;
            result.push_back(digitSum);
        }
        
        if (overflow != 0) {
            result.push_back(overflow + '0');
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    string product(const string &x, const string &y) const {
        string result = "0";
        string zeroes = "";
        
        for (int i = 0; i < y.length(); i++) {
            int yi = (int)y.length() - i - 1;
            int digitY = y[yi] - '0';
            
            string multiply = multiplyByDigit(x, digitY);
            
            multiply += zeroes;
            zeroes.push_back('0');
            result = sum(result, multiply);
        }
        
        return result;
    }
};

ostream& operator << (ostream& out, BigInteger const& x) {
    out << x.value;
    return out;
}

BigInteger bigFactorial(int n) {
    BigInteger result(1);
    
    for (int i = 1; i <= n; i++) {
        BigInteger x(i);
        result *= x;
    }
    
    return result;
}

int main()
{
    int n;
    
    cin >> n;
    
    cout << bigFactorial(n) << endl;
    
    return 0;
}
