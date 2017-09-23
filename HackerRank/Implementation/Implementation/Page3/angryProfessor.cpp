#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isClassCanceled(const vector<int>& arrivals, int k) {
    int arrivedOnTimeCount = 0;
    
    for (int i = 0; i < arrivals.size(); i++) {
        if (arrivals[i] <= 0) {
            arrivedOnTimeCount++;
        }
    }
    
    if (arrivedOnTimeCount >= k) {
        return "NO";
    }
    else {
        return "YES";
    }
    
}

int main() {
    int t;
    
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        
        cin >> n >> k;
        
        vector<int> arrivals(n);
        for (int j = 0; j < n; j++) {
            cin >> arrivals[j];
        }
        
        cout << isClassCanceled(arrivals, k) << endl;
    }
    
    return 0;
}
