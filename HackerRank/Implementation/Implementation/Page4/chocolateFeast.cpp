#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < (int)t; i++) {
        int totalDollars, wrappersPerChocolate, chocolatePrice;
        
        cin >> totalDollars >> chocolatePrice >> wrappersPerChocolate;
        
        int chocolatesBought = totalDollars / chocolatePrice;
        int wrappers = chocolatesBought;
        
        while (wrappers >= wrappersPerChocolate) {
            int buyChocolatesFromWrappers = wrappers / wrappersPerChocolate;
            chocolatesBought += buyChocolatesFromWrappers;
            wrappers = wrappers % wrappersPerChocolate + buyChocolatesFromWrappers;
        }
        
        cout << chocolatesBought << endl;
        
    }
    return 0;
}
