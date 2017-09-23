#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int findDiffIndex(const string& s, const string& t) {
    for (int i = 0; i < s.length(); i++) {
        if (i >= t.length()) {
            return i;
        }
        
        if (s[i] != t[i]) {
            return i;
        }
    }
    
    if (s.length() < t.length()) {
        return (int)s.length();
    }
    
    return -1;
}

string appendAndDelete(const string& s, const string& t, int k) {
    if (k >= s.length() + t.length() + 1) {
        return "Yes";
    }
    
    int firstDiffIndex = findDiffIndex(s, t);
    
    unsigned long minNumberOfOperations;
    
    if (firstDiffIndex == -1) {
        minNumberOfOperations = 0;
    }
    else {
        minNumberOfOperations = s.length() - firstDiffIndex + (t.length() - firstDiffIndex);
    }
    
    if (k < minNumberOfOperations) {
        return "No";
    }
    if ((k - minNumberOfOperations) % 2 == 0) {
        return "Yes";
    }
    
    return "No";
}

int main()
{
    string s, t;
    int k;
    
    cin >> s >> t;
    cin >> k;
    
    cout << appendAndDelete(s, t, k) << endl;
    
    return 0;
}
