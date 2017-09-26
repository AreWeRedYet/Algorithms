#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> count(n + 1, 0);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        count[a[i]]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> missingElements;
    
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            missingElements.push(i);
        }
    }
    
    vector<int> result(n);
    vector<bool> used(n + 1, false);
    int cost = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (count[a[i]] == 1) {
            result[i] = a[i];
            used[a[i]] = true;
        }
        else {
            int currentMin = missingElements.top();
            
            if (currentMin < a[i] || used[a[i]]) {
                result[i] = currentMin;
                missingElements.pop();
                count[a[i]]--;
                cost++;
            }
            else {
                result[i] = a[i];
                used[a[i]] = true;
            }
        }
    }
    
    cout << cost << endl;
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
