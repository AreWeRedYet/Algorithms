#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalNonDivisibleSubset(vector<int> a, int k) {
    transform(a.begin(), a.end(), a.begin(), [k] (int x) {
        return x % k;
    });
    
    sort(a.begin(), a.end());
    
    vector<pair<int, int>> numberCounts;
    
    int prevNumber = a[0];
    int count = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != prevNumber) {
            numberCounts.push_back(make_pair(prevNumber, count));
            prevNumber = a[i];
            count = 1;
        }
        else {
            count++;
        }
    }
    
    numberCounts.push_back(make_pair(a[a.size() - 1], count));
    
    vector<int> largestSet;
    int totalCount = 0;
    for (int i = 0; i < numberCounts.size(); i++) {
        int searchFor = (k + (k - numberCounts[i].first) % k) % k;
        if (numberCounts[i].second != -1) {
            vector<pair<int, int>>::iterator it = lower_bound(numberCounts.begin(), numberCounts.end(), make_pair(searchFor, -1), [] (pair<int,int> x, pair<int,int> y) {
                return x.first < y.first;
            });
            
            if (it != numberCounts.end() && it->second > numberCounts[i].second && it->first == searchFor) {
                totalCount += it->second;
                it->second = -1;
            }
            else if (numberCounts[i].first == searchFor) {
                totalCount++;
                numberCounts[i].second = -1;
            }
            else if (it == numberCounts.end() || it->first != searchFor) {
                    totalCount += numberCounts[i].second;
                    numberCounts[i].second = -1;
            }
        }
    }
    
    return totalCount;
}

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << maximalNonDivisibleSubset(a, k) << endl;
    
    return 0;
}
