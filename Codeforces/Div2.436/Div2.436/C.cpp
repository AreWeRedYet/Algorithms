#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minNumberOfRefuels(long long distance, long long maxGasTank, long long gasLocation, long long k) {
    long long currentGas = maxGasTank;
    
    int result = 0;
    
    for (int i = 0; i < k; i++) {
        long long gasDistance = i % 2 == 0 ? gasLocation : distance - gasLocation;
        currentGas = currentGas - gasDistance;
        
        if (currentGas < 0) {
            return -1;
        }
        
        if (i + 1 == k) {
            if (currentGas < distance - gasDistance) {
                currentGas = maxGasTank;
                result++;
            }
        }
        else if (currentGas < 2 * (distance - gasDistance)) {
            currentGas = maxGasTank;
            result++;
        }
        
        currentGas -= (distance - gasDistance);
    }
    
    if (currentGas < 0) {
        return -1;
    }
    
    return result;
}

int main() {
    long long distance, maxGasTank, gasLocation, k;
    
    cin >> distance >> maxGasTank >> gasLocation >> k;
    
    cout << minNumberOfRefuels(distance, maxGasTank, gasLocation, k) << endl;
    
    return 0;
}
