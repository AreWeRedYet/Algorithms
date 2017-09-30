#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    int splitIndex = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            splitIndex = i;
            break;
        }
    }
    
    int x = stoi(s.substr(0, splitIndex));
    int y = stoi(s.substr(splitIndex + 1));
    
    if (s[splitIndex] == '+') {
        cout << x + y << endl;;
    }
    else {
        cout << x - y << endl;
    }
    
    return 0;
}
