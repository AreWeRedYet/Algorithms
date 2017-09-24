#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countDistinctSorted(vector<int> sticks) {
    sort(sticks.begin(), sticks.end());
    vector<int> result;
    
    int prevNumber = sticks[0];
    int count = 1;
    for (int i = 1; i < sticks.size(); i++) {
        if (sticks[i] != prevNumber ) {
            prevNumber = sticks[i];
            result.push_back(count);
            count = 1;
        }
        else {
            count++;
        }
    }
    
    result.push_back(count);
    
    return result;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> sticks(n);
    
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    
    vector<int> distinctSorted = countDistinctSorted(sticks);
    
    unsigned long totalSticks = sticks.size();
    cout << totalSticks << endl;
    for (int i = 0; i < distinctSorted.size() - 1; i++) {
        totalSticks -= distinctSorted[i];
        cout << totalSticks << endl;
    }
    
    return 0;
}
