#include <iostream>
#include <vector>

using namespace std;

bool isValid(int number, const vector<int> &a, const vector<int> &b) {
    bool valid = true;
    
    for (int i = 0; i < a.size(); i++) {
        if (number % a[i] != 0) {
            valid = false;
            break;
        }
    }
    
    if (!valid) {
        return false;
    }
    
    for (int i = 0; i < b.size(); i++) {
        if (b[i] % number != 0) {
            valid = false;
            break;
        }
    }
    
    return valid;
}

int getTotalX(const vector<int> &a, const vector<int> &b) {
    int maxA = a[0];
    int minB = b[0];
    
    for (int i = 1; i < a.size(); i++) {
        maxA = max(maxA, a[i]);
    }
    
    for (int i = 1; i < b.size(); i++) {
        minB = min(minB, b[i]);
    }
    
    bool isValidMaxA = isValid(maxA, a, b);
    bool isValidMinB = isValid(minB, a, b);
    
    int count = 0;
    
    
    if (isValidMaxA) {
        count++;
    }
    
    if (isValidMinB) {
        count++;
    }
    
    
    for (int i = 2; i < minB/maxA; i++) {
        int x = i*maxA;
        
        if (isValid(x, a, b) && minB % x == 0) {
            count++;
        }
    }
    
    
    return count;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
        cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
