#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateAliceRanks(const vector<int>& scores, const vector<int> aliceScores) {
    vector<int> ranks(scores.size());
    
    int rank = 1;
    ranks[0] = 1;
    
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] < scores[i-1]) {
            rank++;
        }
        
        ranks[i] = rank;
    }
    
    vector<int> aliceRanks;
    
    int j = (int)scores.size() - 1;
    for (int i = 0; i < aliceScores.size(); i++) {
        
        while (j >= 0 && aliceScores[i] >= scores[j]) {
            j--;
        }
        
        if (j == -1) {
            aliceRanks.push_back(1);
        }
        else {
            aliceRanks.push_back(ranks[j] + 1);
        }
    }
    
    return aliceRanks;
}

int main() {
    int n;
    
    cin >> n;
    
    vector<int> scores(n);
    
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    int m;
    
    cin >> m;
    
    vector<int> aliceScores(m);
    
    for (int i = 0; i < m; i++) {
        cin >> aliceScores[i];
    }
    
    vector<int> aliceRanks = calculateAliceRanks(scores, aliceScores);
    
    for (int i = 0; i < aliceRanks.size(); i++) {
        cout << aliceRanks[i] << endl;
    }
    
    return 0;
}
