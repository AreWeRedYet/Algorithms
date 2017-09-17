#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    
    int pagesFromStart = p/2;
    
    if (n % 2 == 0) n++;
    
    int pagesFromEnd = (n - p) / 2;
    
    cout << min(pagesFromStart, pagesFromEnd) << endl;

    return 0;
}
