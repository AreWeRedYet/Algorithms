#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class ChildName {
    Unknown = -1,
    Betty,
    Reggy,
    Size
};

enum class State {
    Losing = 0,
    Weak,
    Strong,
    Size
};

class Vertex {
public:
    ChildName childName;
    vector<shared_ptr<Vertex>> adjacent;
    
    Vertex() {
        childName = ChildName::Unknown;
    }
};

long long calculateValidDivisions(const vector<shared_ptr<Vertex>>& vertices) {
    vector<vector<vector<vector<long long>>>> dp(vertices.size(), vector<vector<vector<long long>>>((int)ChildName::Size, vector<vector<long long>>((int)State::Size)));
    
    
    
}

int main()
{
    int n;
    cin >> n;
    
    vector<shared_ptr<Vertex>> vertices(n);
    for (int i = 0; i < n - 1; i++) {
        int u,v;
        cin >> u >> v;
        vertices[u]->adjacent.push_back(vertices[v]);
        vertices[v]->adjacent.push_back(vertices[u]);
    }
    
    long long countValid = calculateValidDivisions(vertices);
    
    cout << countValid << endl;
    
    return 0;
}
