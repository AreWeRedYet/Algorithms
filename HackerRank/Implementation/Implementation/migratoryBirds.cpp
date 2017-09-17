#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    vector<int> birdType(n);
    
    for (int i = 0; i < n; i++) {
        cin >> birdType[i];
    }
    
    map<int, int> birdTypeToCount;
    
    for (int i = 0; i < birdType.size(); i++) {
        if (birdTypeToCount.find(birdType[i]) == birdTypeToCount.end()) {
            birdTypeToCount[birdType[i]] = 1;
        }
        else
        {
            birdTypeToCount[birdType[i]] += 1;
        }
    }
    
    int mostCommonBirdCount = -1;
    int mostCommonBirdId = -1;
    
    for (map<int, int>::iterator it = birdTypeToCount.begin(); it != birdTypeToCount.end(); it++) {
        if (mostCommonBirdCount < it->second) {
            mostCommonBirdCount = it->second;
            mostCommonBirdId = it->first;
        }
    }
    
    cout << mostCommonBirdId << endl;
    
    return 0;
}
