#include <iostream>

using namespace std;

int likedAfterDays(int n) {
    int liked = 2;
    int totalLiked = 2;
    
    for (int i = 1; i < n; i++) {
        int sharedNumber = liked * 3;
        liked = sharedNumber / 2;
        totalLiked += liked;
    }
    
    return totalLiked;
}

int main() {
    int n;
    
    cin >> n;
    
    cout << likedAfterDays(n) << endl;
    
    return 0;
}
