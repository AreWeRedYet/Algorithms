#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Point {
    int x, y;
} Point;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<vector<char>> map(n, vector<char>(n, 'S'));
    
    Point lastPoint;
    lastPoint.x = 0;
    lastPoint.y = 0;
    
    bool q = false;
    
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            lastPoint.x = 0;
            lastPoint.y = 0;
        }
        else if (lastPoint.x + 2 >= n) {
            lastPoint.x = q ? 0 : 1;
            q = !q;
            lastPoint.y = lastPoint.y + 1;
        }
        else {
            lastPoint.x += 2;
        }
        
        if (lastPoint.y >= n) {
            break;
        }
        
        map[lastPoint.y][lastPoint.x] = 'L';
    }
    
    if (lastPoint.y >= n) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map.size(); j++) {
                cout << map[j][i];
            }
            cout << endl;
        }
    }
    
    return 0;
}
