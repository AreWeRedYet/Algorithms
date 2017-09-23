#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int numberOfValleys(string path) {
    
    bool startedBelow = false;
    int currentHeight = 0;
    int valleyCount = 0;
    
    for (int i = 0; i < path.size(); i++) {
        currentHeight += path[i] == 'U' ? 1 : -1;
        
        if (currentHeight >= 0 && startedBelow) {
            valleyCount++;
            startedBelow = false;
        }
        else if (currentHeight < 0) {
            startedBelow = true;
        }
    }
    
    return valleyCount;
}

int main()
{
    int n;
    cin >> n;
    
    string path;
    cin >> path;
    
    cout << numberOfValleys(path) << endl;
    
    return 0;
}
