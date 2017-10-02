#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long stepsToReduceTo(int chocolate, int value) {
    long long steps = 0;
    
    steps = (chocolate - value) / 5;
    int left = (chocolate - value) % 5;
    
    steps += left / 2;
    left = left % 2;
    
    steps += left;
    
    return steps;
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> chocolates(n);
        for (int i = 0; i < n; i++) {
            cin >> chocolates[i];
        }
        
        vector<int>::iterator minElement = min_element(chocolates.begin(), chocolates.end(), less<int>());
        long long minCount = INT64_MAX;
        for (int value = 0; value < 5; value++) {
            long long count = 0;
            for (int chocolate : chocolates) {
                count += stepsToReduceTo(chocolate, *minElement - value);
            }
            
            minCount = min(minCount, count);
        }
        
        cout << minCount << endl;
    }
    
    return 0;
}
