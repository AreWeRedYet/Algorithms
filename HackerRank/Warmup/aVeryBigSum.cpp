#include <iostream>
#include <vector>

using namespace std;

long long aVeryBigSum(int n, const vector <long long>& ar) {
    long long sum = 0;
    
    for (int i = 0; i < ar.size(); i++)
    {
        sum += ar[i];
    }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<long long> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        cin >> ar[ar_i];
    }
    long long result = aVeryBigSum(n, ar);
    cout << result << endl;
    return 0;
}
