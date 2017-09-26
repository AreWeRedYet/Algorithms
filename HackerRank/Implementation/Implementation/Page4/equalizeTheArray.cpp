#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> arrayCounts;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map<int, int>::iterator element = arrayCounts.find(a[i]);
        
        if (element == arrayCounts.end()) {
            arrayCounts[a[i]] = 1;
        }
        else {
            element->second++;
        }
    }
    
    int maxRepetition = 0;
    for (pair<int,int> it: arrayCounts) {
        maxRepetition = max(maxRepetition, it.second);
    }
    
    cout << n - maxRepetition << endl;
    
    return 0;
}
