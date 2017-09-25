#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    set<int> numberOfDiff;
    int result = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' & s[i] <= 'Z') {
            result = max(result, (int)numberOfDiff.size());
            numberOfDiff.clear();
        }
        else {
            numberOfDiff.insert(s[i]);
        }
    }
    
    result = max(result, (int)numberOfDiff.size());
    
    cout << result << endl;
    
    return 0;
}
