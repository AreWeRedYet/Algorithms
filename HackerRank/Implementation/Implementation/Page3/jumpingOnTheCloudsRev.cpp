#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    vector<int> c(n);
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    int cloudIndex = 0;
    int energy = 100;
    
    do {
        cloudIndex = (cloudIndex + k) % n;
        
        if (c[cloudIndex] == 1) {
            energy -= 2;
        }
        
        energy -= 1;
        
    } while (cloudIndex != 0);
    
    cout << energy << endl;
    
    return 0;
}
