#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class MinMax {
public:
    long long min;
    long long max;
    
    MinMax()
    {}
    
    MinMax(long long min, long long max)
    : min(min), max(max)
    {}
};

int main()
{
    long long n;
    long long p, q, r;
    
    cin >> n >> p >> q >> r;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<MinMax> beginMinMax;
    vector<MinMax> endMinMax;
    
    long long minValue = a[0];
    long long maxValue = a[0];
    
    beginMinMax.push_back(MinMax(minValue, maxValue));
    
    for (int i = 1; i < a.size(); i++) {
        minValue = min(minValue, a[i]);
        maxValue = max(maxValue, a[i]);
        
        beginMinMax.push_back(MinMax(minValue, maxValue));
    }
    
    minValue = a[a.size() - 1];
    maxValue = a[a.size() - 1];
    
    endMinMax.push_back(MinMax(minValue, maxValue));
    
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        minValue = min(minValue, a[i]);
        maxValue = max(maxValue, a[i]);
        
        endMinMax.push_back(MinMax(minValue, maxValue));
    }
    
    long long maxSum = LLONG_MIN;
    
    for (int i = 0; i < n; i++) {
        long long bestP = max(p * beginMinMax[i].min, p * beginMinMax[i].max);
        long long bestR = max(r * endMinMax[i].min, r * endMinMax[i].max);
        
        long long sum = bestP + q * a[i] + bestR;
        
        if (maxSum < sum) {
            maxSum = sum;
        }
    }
    
    cout << maxSum << endl;

    return 0;
}
