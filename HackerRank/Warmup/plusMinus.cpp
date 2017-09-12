#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++) {
        cin >> arr[arr_i];
    }
    
    int zeroes = 0;
    int positive = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) {
            zeroes++;
        }
        else if (arr[i] > 0) {
            positive++;
        }
    }
    
    int negative = n - zeroes - positive;
    
    cout << (double)positive/n << endl << (double)negative/n << endl << (double)zeroes/n << endl;
    
    return 0;
}
