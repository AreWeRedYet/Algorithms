#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string isPossible(const vector<vector<int>>& balls) {
    vector<long long> totalBallsPerType(balls.size(), 0);
    vector<long long> totalBallsPerBox(balls.size(), 0);
    
    for (int i = 0; i < balls.size(); i++) {
        for (int j = 0; j < balls.size(); j++) {
            totalBallsPerBox[i] += (long long) balls[i][j];
            totalBallsPerType[j] += (long long) balls[i][j];
        }
    }
    
    sort(totalBallsPerType.begin(), totalBallsPerType.end());
    sort(totalBallsPerBox.begin(), totalBallsPerBox.end());
    
    for (int i = 0; i < totalBallsPerType.size(); i++) {
        if (totalBallsPerType[i] != totalBallsPerBox[i]) {
            return "Impossible";
        }
    }
    
    return "Possible";
}

int main()
{
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        vector<vector<int>> balls(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> balls[i][j];
            }
        }
        
        cout << isPossible(balls) << endl;
    }
    
    return 0;
}
