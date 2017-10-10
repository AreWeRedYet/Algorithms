#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

string solve(const string &s) {
    if (s[0] != 'a') {
        return "NO";
    }
    
    char prevMaxChar = s[0];
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] - prevMaxChar > 1) {
            return "NO";
        }
        
        prevMaxChar = max(prevMaxChar, s[i]);
    }
    
    return "YES";
}

int main()
{
    string s;
    cin >> s;
    
    cout << solve(s) << endl;
    
    return 0;
}
