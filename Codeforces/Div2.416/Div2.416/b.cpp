#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    
    vector<int> l(m), r(m), x(m);
    
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> x[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        int value = p[x[i] - 1];
        
        int index = l[i];
        
        for (int j = l[i] - 1; j < r[i]; j++)
        {
            if (p[j] < value)
            {
                index++;
            }
        }
        
        if (index == x[i])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    
    return 0;
}

