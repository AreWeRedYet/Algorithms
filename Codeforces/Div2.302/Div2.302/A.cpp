#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    set<char> distinctCharacters;
    distinctCharacters.insert(s[0]);
    vector<string> result;
    string currentString(1, s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (distinctCharacters.find(s[i]) == distinctCharacters.end() && result.size() < n - 1) {
            distinctCharacters.insert(s[i]);
            result.push_back(currentString);
            currentString = s[i];
        }
        else {
            currentString.push_back(s[i]);
        }
    }
    
    result.push_back(currentString);
    
    if (result.size() < n) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }
    
    
    return 0;
}

