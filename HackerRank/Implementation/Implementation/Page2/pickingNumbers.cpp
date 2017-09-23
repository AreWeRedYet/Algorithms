#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pickingNumbers(vector<int> a) {
    sort(a.begin(), a.end());
    
    int prevDiffNumber = a[0];
    
    vector<int> startIndices;
    startIndices.push_back(0);
    
    unsigned long j = 0;
    int startNumber = a[startIndices[j]];
    int maxSize = 0;
    
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != prevDiffNumber) {
            startIndices.push_back(i);
            prevDiffNumber = a[i];
        }
        
        if (a[i] > prevDiffNumber + 1) {
            maxSize = max(maxSize, i - startIndices[j]);
            j = startIndices.size() - 1;
            startNumber = a[i];
            continue;
        }
        
        if (a[i] > startNumber + 1) {
            maxSize = max(maxSize, i - startIndices[j]);
            j++;
            startNumber = a[startIndices[j]];
            continue;
        }
        
        if (i == a.size() - 1) {
            maxSize = max(maxSize, i - startIndices[j] + 1);
        }
    }
    
    return maxSize;
}

int main() {
    int n;
    
    cin >> n;
    
    vector<int> numbers(n);
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    cout << pickingNumbers(numbers) << endl;
    
    return 0;
}
