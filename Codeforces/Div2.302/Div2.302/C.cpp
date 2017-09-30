#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    if (n > s.length()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << s[i] << endl;
        }
        
        cout << s.substr(n - 1) << endl;
    }
    return 0;
}
