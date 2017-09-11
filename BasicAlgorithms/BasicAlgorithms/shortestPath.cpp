#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    
    /**
     Ford graph algorithm for finding shortest paths
     Graph directed/undirected, can have weights < 0. If there is negative cycle we will know

     @param start start node
     @param end end node
     @return shortest path between start and end node
     */
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
    
    int shortestPathDAG(int start, int end)
    {
        stack<int> sortedNodes = topologicalSort();
        vector<int> bestPath(connections.size(), 0);
        vector<bool> visited(connections.size(), false);
        
        visited[start] = true;
        
        for (int i = 0; i < connections.size() - 1; i++) {
            int node = sortedNodes.top();
            sortedNodes.pop();
            
            if (!visited[node]) {
                continue;
            }
            
            for (Edge connection : connections[node]) {
                if (!visited[connection.vertex] || bestPath[connection.vertex] < bestPath[node] + connection.cost)
                {
                    bestPath[connection.vertex] = bestPath[node] + connection.cost;
                    visited[connection.vertex] = true;
                }
            }
        }
        
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
    void dfs(int node, stack<int>& sortedNodes, vector<bool>& visited)
    {
        visited[node] = true;
        
        for (int i = 0; i < connections[node].size(); i++)
        {
            if (visited[connections[node][i].vertex])
            {
                continue;
            }
            
            dfs(connections[node][i].vertex, sortedNodes, visited);
        }
        
        sortedNodes.push(node);
    }
    
    stack<int> topologicalSort()
    {
        vector<bool> visited(connections.size(), false);
        stack<int> sortedNodes;
        
        for (int i = 0; i < connections.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            
            dfs(i, sortedNodes, visited);
        }
        
        return sortedNodes;
    }
    
    /**
     Performs relaxation of edges

     @param bestPaths current best paths
     @param reached nodes we have reached
     */
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
    
    
    /**
     Find all shortest paths from node from

     @param from node from which to find all shortest paths
     @return vector representing all shortest paths from given node
     */
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
        cout << g.shortestPathDijakstra(0, i) << endl;
//        cout << g.shortestPathFord(0, i) << endl;
    }
    
    return 0;
}
