#include <iostream>
#include <vector>

using namespace std;

vector < int > solve(const vector<int>& a, const vector<int>& b){
    
    vector<int> result(2, 0);
    
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])
        {
            result[1]++;
        }
        else if (a[i] > b[i])
        {
            result[0]++;
        }
    }
    
    return result;
}

int main() {
    vector<int> a(3);
    
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    
    vector<int> b(3);
    
    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
    }
    
    vector<int> result = solve(a,b);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;
    
    
    return 0;
}
