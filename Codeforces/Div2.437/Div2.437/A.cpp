#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int countBadFlights = 0, countGoodFlights = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == 'F') {
                countGoodFlights++;
            }
            else {
                countBadFlights++;
            }
        }
    }
    
    if (countGoodFlights > countBadFlights) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
