#include <iostream>
#include <vector>

using namespace std;

class Move {
public:
    int x = 0;
    int y = 0;
    
    Move()
    {}
    
    Move (int x, int y) : x(x), y(y)
    {}
    
    bool canMoveFromLocation(int locationX, int locationY, const vector<vector<int>> &matrix) {
        int n = matrix.size();
        int newLocationX = locationX + x;
        int newLocationY = locationY + y;
        return newLocationX >= 0 && newLocationX < n && newLocationY >= 0 && newLocationY < n && matrix[newLocationX][newLocationY] == 0;
    }
};


Move getSameWindDirection(char wind) {
    switch (wind) {
        case 'n' : return Move(-1, 0);
        case 's' : return Move(1, 0);
        case 'e' : return Move(0, 1);
        case 'w' : return Move(0, -1);
    }
    
    throw "Error";
}

vector<Move> getPreferredMoves(char wind) {
    vector<Move> moves(4);
    
    moves[0] = getSameWindDirection(wind);
    moves[1] = wind == 'n' || wind == 's' ? Move(0, 1) : Move(1, 0);
    moves[2] = wind == 'n' || wind == 's' ? Move(0, -1) : Move(-1, 0);
    moves[3] = Move(-moves[0].x, -moves[0].y);
    
    return moves;
}

int main() {
    int n;
    
    cin >> n;
    
    char wind;
    cin >> wind;
    
    int locationX, locationY;
    
    cin >> locationX >> locationY;
    
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    vector<Move> prefferedMoves = getPreferredMoves(wind);
    
    matrix[locationX][locationY] = 1;
    
    for (int i = 2; i <= n*n; i++) {
        for (Move& move: prefferedMoves) {
            if (move.canMoveFromLocation(locationX, locationY, matrix)) {
                locationX += move.x;
                locationY += move.y;
                break;
            }
        }
        matrix[locationX][locationY] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j != n - 1) {
                cout << " ";
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
