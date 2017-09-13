#include <iostream>
#include <vector>

using namespace std;

struct house {
    int fallenApples = 0;
    int fallenOranges = 0;
};

struct house fallOnHouse(int s, int t, int a, int b, const vector<int> &apple, const vector<int>& orange) {
    struct house result;
    for (int i = 0; i < apple.size(); i++) {
        if (a + apple[i] >= s && a + apple[i] <= t)
        {
            result.fallenApples++;
        }
    }
    
    for (int i = 0; i < orange.size(); i++) {
        if (b + orange[i] <= t && b + orange[i] >= s) {
            result.fallenOranges++;
        }
    }
    
    return result;
}


int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
        cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
        cin >> orange[orange_i];
    }
    
    struct house result = fallOnHouse(s, t, a, b, apple, orange);
    
    cout << result.fallenApples << endl;
    cout << result.fallenOranges << endl;
    
    return 0;
}

