#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum Field {
    Unknown,
    Blocked,
    Lose,
    Win
};

typedef struct Path {
    int winCount = 0;
    int loseCount = 0;
} Path;


bool isCorner(vector<vector<Field>> &chessBoardInfo, int i, int j) {
    return chessBoardInfo[i - 1][j - 1] == Blocked && chessBoardInfo[i][j - 1] == Blocked && chessBoardInfo[i - 1][j] == Blocked;
}

bool canWin(vector<vector<Field>> &chessBoardInfo, int i, int j) {
    return chessBoardInfo[i - 1][j] == Win || chessBoardInfo[i][j - 1] == Win || chessBoardInfo[i - 1][j - 1] == Win;
}

int countWinsOrLoses(vector<vector<Field>> &chessBoardInfo, int i, int j, Field f) {
    int count = 0;
    
    if (chessBoardInfo[i - 1][j - 1] == f) count++;
    if (chessBoardInfo[i][j - 1] == f) count++;
    if (chessBoardInfo[i - 1][j] == f) count++;
    
    return count;
}

int calculateWinCount(const vector<vector<char>>& chessBoard) {
    vector<vector<Field>> chessBoardInfo(chessBoard.size(), vector<Field>(chessBoard.size(), Unknown));
    
    for (int i = 0; i < chessBoard.size(); i++) {
        for (int j = 0; j < chessBoard.size(); j++) {
            switch (chessBoard[i][j]) {
                case 'X':
                    chessBoardInfo[i][j] = Blocked;
                    break;
            }
        }
    }
    
    for (int i = 1; i < chessBoardInfo.size(); i++) {
        for (int j = 1; j < chessBoardInfo.size(); j++) {
            if (chessBoardInfo[i][j] == Unknown && isCorner(chessBoardInfo, i, j)) {
                chessBoardInfo[i][j] = Win;
            }
        }
    }
    
    for (int i = 1; i < chessBoardInfo.size(); i++) {
        for (int j = 1; j < chessBoardInfo.size(); j++) {
            if (chessBoardInfo[i][j] == Unknown && canWin(chessBoardInfo, i, j)) {
                chessBoardInfo[i][j] = Lose;
            } else if (chessBoardInfo[i][j] != Blocked){
                chessBoardInfo[i][j] = Win;
            }
        }
    }
    
    vector<Path> countWays;
    
    for (int i = 1; i < chessBoard.size(); i++) {
        for (int j = 1; j < chessBoard.size(); j++) {
            if (chessBoard[i][j] == 'K' && !isCorner(chessBoardInfo, i, j)) {
                Path path;
                path.winCount = countWinsOrLoses(chessBoardInfo, i, j, Win);
                path.loseCount = countWinsOrLoses(chessBoardInfo, i, j, Lose);
                countWays.push_back(path);
            }
        }
    }
    
    int onlyWin = 0;
    int winAndLoss = 0;
    int onlyLoss = 0;
    
    for (int i = 0; i < countWays.size(); i++) {
        if (countWays[i].winCount > 0 && countWays[i].loseCount > 0) {
            winAndLoss++;
        } else if (countWays[i].winCount > 0) {
            onlyWin++;
        } else if (countWays[i].loseCount > 0) {
            onlyLoss++;
        } else {
            throw "Should never happen";
        }
    }
    
    int winCount = 0;
    
    if ((winAndLoss % 2 == 0 && winAndLoss > 0 && (onlyWin + onlyLoss) % 2 == 1) ||
        (winAndLoss == 0 && onlyWin % 2 == 1)) {
        for (int i = 0; i < countWays.size(); i++) {
            if (countWays[i].loseCount == 0 || countWays[i].winCount == 0) {
                winCount += countWays[i].winCount;
                winCount += countWays[i].loseCount;
            }
        }
    } else if (winAndLoss % 2 == 1 && winAndLoss > 1 && (onlyWin + onlyLoss) % 2 == 0) {
        for (int i = 0; i < countWays.size(); i++) {
            winCount += countWays[i].winCount;
            winCount += countWays[i].loseCount;
        }
    } else if (winAndLoss == 1) {
        for (int i = 0; i < countWays.size(); i++) {
            if (countWays[i].winCount > 0 && countWays[i].loseCount > 0) {
                winCount += onlyWin % 2 == 0 ? countWays[i].winCount : countWays[i].loseCount;
            }
        }
    }
    
    return winCount;
}

int main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        
        vector<vector<char>> chessBoard(n + 1, vector<char>(n + 1, 'X'));
        
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> chessBoard[i][j];
            }
        }
        
        int winCount = calculateWinCount(chessBoard);
        
        if (winCount > 0) {
            cout << "WIN " << winCount << endl;
        } else {
            cout << "LOSE" << endl;
        }
    }
    
    return 0;
}
