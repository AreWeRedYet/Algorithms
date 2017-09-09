#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Edge
{
public:
    int nodeId;
    int cost;
    
    Edge(int nodeId, int cost): nodeId(nodeId), cost(cost)
    {}
};

class Graph
{
public:
    vector<vector<Edge>> connections;
    
    Graph(vector<vector<Edge>> connections): connections(connections)
    {}
    
    int shortestPathDijakstra()
    {
        // TODO
        return 0;
    }
    
    int shortestPathFord()
    {
        // TODO
        return 0;
    }
    
    int shortestPathDAG()
    {
        // TODO
        return 0;
    }
    
    vector<vector<int>> allPairsShortestPath()
    {
        // TODO
        unsigned long n = connections.size();
        return vector<vector<int>>(n);
    }
    
    vector<vector<int>> allPairsMatrixMul()
    {
        //TODO
        unsigned long n = connections.size();
        return vector<vector<int>>(n);
    }
};

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<Edge>> connections(n);
    
    for (int i = 0; i < n; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        Edge e(y, cost);
        
        connections[x].push_back(e);
    }
    
    Graph g(connections);
    
    return 0;
}
