#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> height(n);
    
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    
    int maxHeight = height[0];
    
    for (int i = 1; i < height.size(); i++) {
        maxHeight = max(maxHeight, height[i]);
    }
    
    cout << max(maxHeight - k, 0) << endl;
    
    return 0;
}
