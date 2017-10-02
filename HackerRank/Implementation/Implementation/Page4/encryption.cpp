#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int maxSize = ceil(sqrt(s.length()));
    
    int rows = maxSize, columns = maxSize;
    
    if ((rows - 1) * columns >= s.length()) {
        rows--;
    }
    
    vector<string> matrix(rows, "");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i * columns + j < s.length()) {
                matrix[i].push_back(s[i * columns + j]);
            }
        }
    }
    
    string result = "";
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            if (j <= matrix[i].length() - 1) {
                result.push_back(matrix[i][j]);
            }
        }
        
        if (j != columns - 1) {
            result.push_back(' ');
        }
    }
    
    cout << result << endl;
    
    return 0;
}
