#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> scores(n);
    
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    int countNewWorst = 0;
    int countNewBest = 0;
    int min = scores[0];
    int max = scores[0];
    for (int i = 1; i < n; i++) {
        if (min > scores[i]) {
            min = scores[i];
            countNewWorst++;
        }
        
        if (max < scores[i]) {
            max = scores[i];
            countNewBest++;
        }
    }
    
    cout << countNewBest << " " << countNewWorst << endl;
    
    return 0;
}
