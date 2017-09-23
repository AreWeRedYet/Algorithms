#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countDigitDivisors(int n) {
    int count = 0;
    
    int startingNumber = n;
    
    while (n > 0) {
        int digit = n % 10;
        n = n / 10;
        
        if (digit != 0 && startingNumber % digit == 0) {
            count++;
        }
    }
    
    return count;
}

int main()
{
    int t;
    
    cin >> t;
    
    vector<int> numbers(t);
    
    for (int i = 0; i < t; i++) {
        cin >> numbers[i];    }
    
    for (int i = 0; i < t; i++) {
        cout << countDigitDivisors(numbers[i]) << endl;
    }
    
    return 0;
}
