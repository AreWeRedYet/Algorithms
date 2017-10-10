#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

enum ChoiceType {
    MinTaken,
    MaxTaken
};

long long calculateMaxSum(const vector<int> array) {
    int maxElement = *(max_element(array.begin(), array.end(), less<int>()));
    vector<vector<long long>> dp(array.size(), vector<long long>(2, 0));
    
    for (int i = 1; i < array.size(); i++) {
        for (int currType = MinTaken; currType <= MaxTaken; currType++) {
            int currValue = currType == MinTaken ? 1 : array[i];
            for (int prevType = MinTaken; prevType <= MaxTaken; prevType++) {
                int prevValue = prevType == MinTaken ? 1 : array[i - 1];
                
                long long newValue = dp[i - 1][prevType] + abs(currValue - prevValue);
                dp[i][currType] = max(dp[i][currType], newValue);
            }
        }
    }
    
    long long maxSum = *(max_element(dp[array.size() - 1].begin(), dp[array.size() - 1].end(), less<int>()));
    
    return maxSum;
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        long long maxSum = calculateMaxSum(b);
        
        cout << maxSum << endl;
    }
    return 0;
}
