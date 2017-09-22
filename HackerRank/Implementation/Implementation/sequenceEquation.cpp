#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IndexNumber {
public:
    int value;
    int index;
    
    IndexNumber(int value, int index) :
    value(value),
    index(index)
    {
    }
    
    bool operator < (const IndexNumber& n) const {
        return this->value < n.value;
    }
};

int main() {
    int n;
    
    cin >> n;
    
    vector<IndexNumber> p(n, IndexNumber(0, -1));
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        
        p[i] = IndexNumber(value, i+1);
    }
    
    sort(p.begin(), p.end());
    
    vector<int> result(n);
    
    for (int i = 1; i <= n; i++) {
        IndexNumber searchValue(i, -1);
        
        for (int j = 0; j < 2; j++) {
            auto it = lower_bound(p.begin(), p.end(), searchValue);
            
            if (it == p.end() || (it->value != searchValue.value))
            {
                throw "Something is really wrong";
            }
            else
            {
                searchValue = IndexNumber(it->index, -1);
            }
        }
        
        result[i-1] = searchValue.value;
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}
