#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        cout << "home" << endl;
    }
    else {
        cout << "contest" << endl;
    }
    
    return 0;
}
