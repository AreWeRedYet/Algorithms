#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> sockColors(n);
    
    for (int i = 0; i < n; i++) {
        cin >> sockColors[i];
    }
    
    map<int, int> colorToCount;
    
    for (int i = 0; i < n; i++) {
        if (colorToCount.find(sockColors[i]) == colorToCount.end()) {
            colorToCount[sockColors[i]] = 1;
        }
        else {
            colorToCount[sockColors[i]]++;
        }
    }
    
    int totalNumberOfPairs = 0;
    
    for (map<int,int>::iterator it = colorToCount.begin(); it != colorToCount.end(); it++) {
        totalNumberOfPairs += it->second / 2;
    }
    
    cout << totalNumberOfPairs << endl;
    
    return 0;
}
