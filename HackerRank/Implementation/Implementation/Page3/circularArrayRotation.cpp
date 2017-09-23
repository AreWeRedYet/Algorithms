#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, q;
    
    cin >> n >> k >> q;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
    for (int i = 0; i < q; i++) {
        cout << a[(n + (queries[i] - k) % n) % n] << endl;
    }
    
    return 0;
}
