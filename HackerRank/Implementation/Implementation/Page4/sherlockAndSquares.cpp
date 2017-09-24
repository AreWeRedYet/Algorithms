#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int countSquares(int A, int B) {
    int startNumber = (int)trunc(sqrt(A));
    int endNumber = (int)ceil(sqrt(B));
    
    if (startNumber * startNumber < A) {
        startNumber++;
    }
    
    if (endNumber * endNumber > B) {
        endNumber--;
    }
    
    return endNumber - startNumber + 1;
}

int main()
{
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        cout << countSquares(A, B) << endl;
    }
    
    return 0;
}
