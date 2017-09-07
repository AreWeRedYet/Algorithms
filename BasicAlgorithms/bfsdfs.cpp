#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
	int n;
	vector<vector<int>> roads;

	Graph(int n, vector<vector<int>> roads): n(n), roads(roads)
	{}
	
	bool areConnectedBfs(int startCity, int endCity)
	{
		vector<bool> visited(n, false);

		queue<int> cities;
		cities.push(startCity);
		
			while (!cities.empty())
			{
				int currentCity = cities.front();
		
				cities.pop();
		
				if (endCity == currentCity)
				{
					return true;
				}
				
				visited[currentCity] = true;
		
				for (int i = 0; i < roads[currentCity].size(); i++)
				{
					if (!visited[roads[currentCity][i]])
					{
						cities.push(roads[currentCity][i]);
					}
				}
			}
		
			return false;
	}

	bool areConnectedDfs(int startCity, int endCity)
	{
		vector<bool> visited(n, false);

		return dfs(startCity, endCity, visited);
	}

private:
	bool dfs(int startCity, int endCity, vector<bool>& visited)
	{
		if (startCity == endCity)
		{
			return true;
		}

		visited[startCity] = true;

		bool areConnected = false;

		for (int i = 0; i < roads[startCity].size(); i++)
		{
			if (!visited[roads[startCity][i]])
			{
				areConnected = dfs(roads[startCity][i], endCity, visited);
			}

			if (areConnected)
			{
				return true;
			}
		}

		return false;
	}
};

int main()
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> connected(n);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		connected[x].push_back(y);
		connected[y].push_back(x);
	}

	Graph g = Graph(n, connected);

	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int startCity, endCity;	
		cin >> startCity >> endCity;
	
		bool areConnected = g.areConnectedBfs(startCity, endCity);	
		cout << (areConnected ? "YES" : "NO") << endl;		
	}
		
	return 0;
}