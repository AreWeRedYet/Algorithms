#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isMagic(vector<vector<int>> matrix) {
    int sum = matrix[0][0] + matrix[1][1] + matrix[2][2];
    
    int n = (int)matrix.size();
    
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = 0; j < n; j++) {
            currentSum += matrix[i][j];
        }
        
        if (currentSum != sum) {
            return false;
        }
    }
    
    for (int j = 0; j < n; j++) {
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += matrix[i][j];
        }
        
        if (currentSum != sum) {
            return false;
        }
    }
    
    int currentSum = matrix[0][2] + matrix[1][1] + matrix[2][0];
    
    if (currentSum != sum) {
        return false;
    }
    
    return true;
}

vector<vector<int>> createMatrix(const vector<int>& v) {
    int n = (int)round(sqrt(v.size()));
    vector<vector<int>> matrix(n, vector<int>(n));
    
    int position = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = v[position++];
        }
    }
    
    return matrix;
}

void swap(vector<int>& vectorToSwap, int i, int j) {
    int tmp = vectorToSwap[i];
    vectorToSwap[i] = vectorToSwap[j];
    vectorToSwap[j] = tmp;
}

int calculateDiff(vector<vector<int>> endMatrix, vector<vector<int>> startMatrix) {
    int n = (int)startMatrix.size();
    int cost = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost += abs(startMatrix[i][j] - endMatrix[i][j]);
        }
    }
    
    return cost;
}

int minCostMagic(vector<int>& permutation, int currentIndex, const vector<vector<int>>& startingMatrix) {
    if (currentIndex == permutation.size() - 1) {
        vector<vector<int>> matrixFromVector = createMatrix(permutation);
        if (isMagic(matrixFromVector)) {
            int cost = calculateDiff(matrixFromVector, startingMatrix);
            
            return cost;
        }
    }
    
    int minCost = 1000000;
    
    for (int i = currentIndex; i < permutation.size(); i++) {
        swap(permutation, currentIndex, i);
        
        int cost = minCostMagic(permutation, currentIndex + 1, startingMatrix);
        
        
        if (minCost > cost) {
            minCost = cost;
        }
        
        swap(permutation, i, currentIndex);
    }
    
    return minCost;
}



int main()
{
    const int n = 3;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> permutation(n * n);
    for (int i = 0; i < n * n; i++) {
        permutation[i] = i + 1;
    }
    
    cout << minCostMagic(permutation, 0, matrix) << endl;
    
    return 0;
}
