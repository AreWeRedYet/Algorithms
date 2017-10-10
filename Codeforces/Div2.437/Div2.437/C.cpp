#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    
    vector<long long> s(n), a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i] >> b[i];
    }
    
    long long totalSlicesCount = accumulate(s.begin(), s.end(), 0);
    
    long long minPizzasCount = totalSlicesCount / s + (totalSlicesCount % s != 0 ? 1 : 0);
    
    return 0;
}
