#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buyMaximum(vector<int> keyboardPrices, vector<int> mousePrices, int s) {
    int maxSum = -1;
    
    sort(keyboardPrices.begin(), keyboardPrices.end());
    sort(mousePrices.begin(), mousePrices.end(), greater<int>());
    
    for (int i = 0; i < keyboardPrices.size(); i++) {
        vector<int>::iterator maximumMousePriceIterator = lower_bound(mousePrices.begin(), mousePrices.end(), s - keyboardPrices[i], greater<int>());
        
        if (maximumMousePriceIterator != mousePrices.end()) {
            int maximumMousePrice = *maximumMousePriceIterator;
            
            int sum = maximumMousePrice + keyboardPrices[i];
            
            if (maxSum < sum && sum <= s) {
                maxSum = sum;
            }
        }
    }
    
    return maxSum;
}

int main()
{
    int s, n, m;
    
    cin >> s >> n >> m;
    
    vector<int> keyboardPrices(n);
    
    for (int i = 0; i < n; i++) {
        cin >> keyboardPrices[i];
    }
    
    vector<int> mousePrices(m);
    
    for (int i = 0; i < m; i++) {
        cin >> mousePrices[i];
    }
    
    int maxSum = buyMaximum(keyboardPrices, mousePrices, s);
    
    cout << maxSum << endl;
    
    return 0;
}
