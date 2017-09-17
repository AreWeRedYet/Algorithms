#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bonAppetit(long long charged, vector<int> &costs, int k) {
    long long realPrice = 0;
    long long totalRealPrice = 0;
    
    for (int i = 0; i < costs.size(); i++) {
        if (i != k) {
            totalRealPrice += costs[i];
        }
    }
    
    realPrice = totalRealPrice / 2;
    
    if (realPrice == charged) {
        cout << "Bon Appetit" << endl;
    }
    else {
        cout << charged - realPrice << endl;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> costs(n);
    
    for (int i = 0; i < costs.size(); i++) {
        cin >> costs[i];
    }
    
    long long charged;
    
    cin >> charged;
    
    bonAppetit(charged, costs, k);
    
    return 0;
}
