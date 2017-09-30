#include <iostream>
#include <vector>

using namespace std;

typedef struct Volcano {
    int x = 0, y = 0, w = 0;
} Volcano;

int main() {
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    vector<Volcano> volcanos(m);
    for (int i = 0; i < m; i++) {
        cin >> volcanos[i].x >> volcanos[i].y >> volcanos[i].w;
    }
    
    int maxEffect = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int effect = 0;
            for (Volcano v: volcanos) {
                effect += max(v.w - max(abs(v.x - i), abs(v.y - j)), 0);
            }
            
            maxEffect = max(maxEffect, effect);
        }
    }
    
    cout << maxEffect << endl;
    
    return 0;
}
