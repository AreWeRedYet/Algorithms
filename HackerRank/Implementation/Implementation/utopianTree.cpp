#include <iostream>
#include <vector>

using namespace std;

int utopianTreeHeight(int n) {
    int height = 1;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            height *= 2;
        }
        else {
            height++;
        }
    }
    
    return height;
}

int main() {
    int t;
    
    cin >> t;
    
    vector<int> height(t);
    
    for (int i = 0; i < t; i++) {
        cin >> height[i];
    }
    
    for (int i = 0; i < height.size(); i++) {
        cout << utopianTreeHeight(height[i]) << endl;
    }
    
    return 0;
}
