#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    set<string> namesSet;
    
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        auto it = namesSet.find(name);
        
        if (it == namesSet.end()) {
            cout << "NO" << endl;
            namesSet.insert(name);
        }
        else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
