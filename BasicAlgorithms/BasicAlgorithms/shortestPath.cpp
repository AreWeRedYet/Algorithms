#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int vertex;
    int cost;
    
    Edge(int vertex, int cost): vertex(vertex), cost(cost)
    {}
};

class PathTotalCost
{
public:
    int vertex;
    int totalCost;
    
    PathTotalCost(int vertex, int totalCost): vertex(vertex), totalCost(totalCost)
    {}
    
    friend bool operator < (const PathTotalCost& x, const PathTotalCost& y)
    {
        return x.totalCost < y.totalCost;
    }
    
    friend bool operator > (const PathTotalCost& x, const PathTotalCost& y)
    {
        return x.totalCost > y.totalCost;
    }
};

class Graph
{
public:
    vector<vector<Edge>> connections;
    
    Graph(vector<vector<Edge>> connections): connections(connections)
    {}
    
    // Graph - undirected/directed
    // Graph - simple (no loops, no multiple edges for same 2 vertices)
    // Graph - weights > 0
    int shortestPathDijakstra(int start, int end)
    {
        vector<int> allShortestPathsFromStart = allShortestPathsFrom(start);
        
        return allShortestPathsFromStart[end];
    }
    
  
    // Graph - directed
    // Graph - can have weights < 0 (that's why it needs to be directed)
    // Graph - simple (no loops, no multiple edges for same 2 vertices)
    // Can determine if there is negative cycle between edges (u,v)
    int shortestPathFord(int start, int end)
    {
        vector<bool> reached(connections.size(), false);
        vector<int> bestPaths(connections.size());
        int inf = 1000000000;
        
        bestPaths[start] = 0;
        reached[start] = true;
        
        for (int i = 0; i < connections.size() - 1; i++)
        {
            relaxationOnEdges(bestPaths, reached);
        }
        
        bool hasNegativeCycle = false;
        
        for (int i = 0; i < connections.size() - 1; i++)
        {
            for (int j = 0; j < connections[i].size(); j++)
            {
                if (reached[connections[i][j].vertex] && bestPaths[connections[i][j].vertex] > bestPaths[i] + connections[i][j].cost)
                {
                    hasNegativeCycle = true;
                    break;
                }
            }
        }
        
        if (hasNegativeCycle)
        {
            throw "Has negative cycle";
        }
        
        return reached[end] ? bestPaths[end] : inf;
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
    
private:
    
    void relaxationOnEdges(vector<int> &bestPaths, vector<bool> &reached) {
        for (int i = 0; i < connections.size(); i++)
        {
            for (int j = 0; j < connections[i].size(); j++)
            {
                if (reached[i] && (!reached[connections[i][j].vertex] || bestPaths[connections[i][j].vertex] > bestPaths[i] + connections[i][j].cost))
                {
                    bestPaths[connections[i][j].vertex] = bestPaths[i] + connections[i][j].cost;
                    reached[connections[i][j].vertex] = true;
                }
            }
        }
    }
    
    // Calculate all shortest paths starting from "from" node
    vector<int> allShortestPathsFrom(int from)
    {
        vector<int> bestPaths(connections.size(), -1);
        
        bestPaths[from] = 0;
        priority_queue<PathTotalCost, vector<PathTotalCost>, greater<PathTotalCost>> q;
        
        q.push(PathTotalCost(from, 0));
        
        while(!q.empty())
        {
            PathTotalCost pathTotalCost = q.top();
            
            q.pop();
            
            for (int i = 0; i < connections[pathTotalCost.vertex].size(); i++)
            {
                Edge edge = connections[pathTotalCost.vertex][i];
                
                if (bestPaths[edge.vertex] == -1 || bestPaths[edge.vertex] > bestPaths[pathTotalCost.vertex] + edge.cost)
                {
                    bestPaths[edge.vertex] = bestPaths[pathTotalCost.vertex] + edge.cost;
                    q.push(PathTotalCost(edge.vertex, bestPaths[edge.vertex]));
                }
            }
        }
        
        return bestPaths;
    }
};

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<Edge>> connections(n);
    
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        Edge e1(y, cost);
        Edge e2(x, cost);
        
        connections[x].push_back(e1);
        connections[y].push_back(e2);
    }
    
    Graph g(connections);
    
    for (int i = 0; i < n; i++)
    {
//        cout << g.shortestPathDijakstra(0, i) << endl;
        cout << g.shortestPathFord(0, i) << endl;
    }
    
    return 0;
}
