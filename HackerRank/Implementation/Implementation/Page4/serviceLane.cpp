#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    
    vector<int> widths(n);
    
    for (int &width: widths) {
        cin >> width;
    }
    
    for (int i = 0; i < t; i++) {
        int startSegment, endSegment;
        cin >> startSegment >> endSegment;
        int minSize = INT_MAX;
        for (int i = startSegment; i <= endSegment; i++) {
            minSize = min(minSize, widths[i]);
        }
        
        cout << minSize << endl;
    }
    
    return 0;
}
