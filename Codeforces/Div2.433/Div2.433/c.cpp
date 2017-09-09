#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Flight
{
public:
    int t;
    int cost;
    
    Flight(): t(0), cost(0)
    {}
    
    Flight(int t, int cost): t(t), cost(cost)
    {}
    
    bool operator < (const Flight& flight) const
    {
        return this->cost < flight.cost;
    }
};

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    vector<Flight> c(n);
    vector<int> costs(n);
    
    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        c[i] = Flight(i, cost);
        
        costs[i] = cost;
    }
    
    priority_queue<Flight> q;
        
    for (int i = 0; i < k; i++)
    {
        q.push(c[i]);
    }
    
    vector<int> order(n);
    
    for (int i = k; i < n + k; i++)
    {
        if (i < n)
        {
            q.push(c[i]);
        }
        
        Flight bestFlight = q.top();
        
        q.pop();
        
        order[bestFlight.t] = i;
    }
    
    long long totalCost = 0;
    
    for (int i = 0; i < n; i++)
    {
        totalCost += (long long) costs[i]*(order[i] - i);
    }
    
    cout << totalCost << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << order[i] + 1 << " ";
    }
    
    cout << endl;
    
    return 0;
}

