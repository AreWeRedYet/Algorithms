#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector <int> s, int d, int m){
    int numberOfWays = 0;
    
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += s[i];
    }
    
    if (sum == d) {
        numberOfWays++;
    }
    
    for (int i = m; i < n; i++) {
        sum = sum + s[i] - s[i - m];
        if (sum == d) {
            numberOfWays++;
        }
    }
    
    return numberOfWays;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
        cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
