#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> arr(5);
    long long totalSum = 0;
    for(int arr_i = 0; arr_i < 5; arr_i++){
        cin >> arr[arr_i];
        totalSum += arr[arr_i];
    }
    
    long long minSum = totalSum - arr[4];
    long long maxSum = totalSum - arr[4];
    
    for (int i = 0; i < 4; i++)
    {
        minSum = min(minSum, totalSum - arr[i]);
        maxSum = max(maxSum, totalSum - arr[i]);
    }
    
    cout << minSum << " " << maxSum << endl;
    
    return 0;
}
