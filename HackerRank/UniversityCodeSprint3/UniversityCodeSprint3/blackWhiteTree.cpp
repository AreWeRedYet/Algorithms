#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

enum Color {
    Black,
    White
};

enum DiffType {
    WhiteBlack,
    BlackWhite
};

class Vertex {
public:
    int id;
    Color color;
    vector<Vertex*> adjacent;
    int bestWhiteBlackDiff;
    int bestBlackWhiteDiff;
    vector<Vertex*> bestWhiteBlackDiffChildren;
    vector<Vertex*> bestBlackWhiteDiffChildren;
    
    Vertex(): bestWhiteBlackDiff(0), bestBlackWhiteDiff(0)
    {}
    
    void fillDiffs(const Vertex* parent) {
        if (parent != nullptr && adjacent.size() == 1) {
            bestWhiteBlackDiff = this->color == White ? 1 : 0;
            bestBlackWhiteDiff = this->color == Black ? 1 : 0;
            return;
        }
        
        for (Vertex* child: adjacent) {
            if (child == parent) {
                continue;
            }
            
            child->fillDiffs(this);
        }
        
        for (Vertex* child: adjacent) {
            if (child == parent) {
                continue;
            }
            
            if (child->bestWhiteBlackDiff > 0) {
                bestWhiteBlackDiff += child->bestWhiteBlackDiff;
                bestWhiteBlackDiffChildren.push_back(child);
            }
            
            if (child->bestBlackWhiteDiff > 0) {
                bestBlackWhiteDiff += child->bestBlackWhiteDiff;
                bestBlackWhiteDiffChildren.push_back(child);
            }
        }
        
        bestWhiteBlackDiff += (this->color == White) ? 1 : -1;
        bestBlackWhiteDiff += (this->color == Black) ? 1 : -1;
        
        if (bestWhiteBlackDiff <= 0) {
            bestWhiteBlackDiff = 0;
            bestWhiteBlackDiffChildren.clear();
        }
        
        if (bestBlackWhiteDiff <= 0) {
            bestBlackWhiteDiff = 0;
            bestBlackWhiteDiffChildren.clear();
        }
    }
    
    void getMaxDiffNodes(DiffType diffType, vector<int>& maxDiffNodes) {
        maxDiffNodes.push_back(this->id);
        
        vector<Vertex*>& maxDiffChildren = diffType == WhiteBlack ? bestWhiteBlackDiffChildren : bestBlackWhiteDiffChildren;
        
        for (Vertex* child : maxDiffChildren) {
            child->getMaxDiffNodes(diffType, maxDiffNodes);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    
    vector<Vertex> vertices(n);
    
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        vertices[i].color = color == 0 ? White : Black;
        vertices[i].id = i + 1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        
        vertices[x - 1].adjacent.push_back(&vertices[y - 1]);
        vertices[y - 1].adjacent.push_back(&vertices[x - 1]);
    }
    
    Vertex* rootNode = &vertices[0];
    Vertex* parentRootNode = nullptr;
    
    rootNode->fillDiffs(parentRootNode);
    
    Vertex* maxNodeDiff = nullptr;
    int maxDiff = -1;
    
    for (int i = 0; i < n; i++) {
        int diff = max(vertices[i].bestWhiteBlackDiff, vertices[i].bestBlackWhiteDiff);
        if (maxDiff < diff) {
            maxDiff = diff;
            maxNodeDiff = &vertices[i];
        }
    }
    
    DiffType diffType;
    
    diffType = maxNodeDiff->bestWhiteBlackDiff > maxNodeDiff->bestBlackWhiteDiff ? WhiteBlack : BlackWhite;
    
    cout << maxDiff << endl;
    vector<int> maxDiffNodesIds;
    maxNodeDiff->getMaxDiffNodes(diffType, maxDiffNodesIds);
    
    cout << maxDiffNodesIds.size() << endl;
    
    for (int i = 0; i < maxDiffNodesIds.size(); i++) {
        cout << maxDiffNodesIds[i];
        
        if (i != maxDiffNodesIds.size() - 1) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }
    
    return 0;
}
