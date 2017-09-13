#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canLand(int x1, int v1, int x2, int v2) {
    if (v1 == v2)
    {
        return x1 == x2;
    }
    
    return (x1 - x2)/(v2 - v1) >= 0 && (x1 - x2) % (v2 - v1) == 0;
}

int main()
{
    int x1, v1, x2, v2;
    
    cin >> x1 >> v1 >> x2 >> v2;
    
    bool result = canLand(x1, v1, x2, v2);
    
    cout << (result ? "YES" : "NO") << endl;
    
    return 0;
}
