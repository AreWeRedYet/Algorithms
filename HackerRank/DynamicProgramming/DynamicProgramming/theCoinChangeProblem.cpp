#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> c(m);
    
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i + 1][j] = dp[i][j];
            if (c[i] <= j) {
                dp[i + 1][j] += dp[i + 1][j - c[i]];
            }
        }
    }
    
    cout << dp[m][n] << endl;
    
    return 0;
}
