#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> counts;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        map<int, int>::iterator it = counts.find(a[i]);
        
        if (it == counts.end()) {
            counts.insert(make_pair(a[i], 1));
        }
        else {
            it->second++;
        }
    }
    
    if (counts.size() != 2) {
        cout << "NO" << endl;
    } else {
        if (counts.begin()->second == next(counts.begin())->second) {
            cout << "YES" << endl;
            cout << counts.begin()->first << " " << next(counts.begin())->first << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
