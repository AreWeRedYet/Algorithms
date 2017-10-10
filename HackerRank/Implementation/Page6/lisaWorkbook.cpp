#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> t(n);
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    int count = 0;
    
    int pageNumber = 1;
    for (int i = 0; i < n; i++) {
        if (t[i] <= k) {
            if (t[i] >= pageNumber) {
                count++;
            }
        }
        else {
            int startPageNumber = pageNumber;
            pageNumber += (t[i] - 1) / k;
            
            int totalProblems = 0;
            for (int j = startPageNumber; j <= pageNumber; j++) {
                int totalProblemsStart = totalProblems;
                totalProblems += min(k, t[i] - totalProblems);
                
                if (totalProblems >= j && totalProblemsStart <= j) {
                    count++;
                }
            }
        }
        
        pageNumber++;
    }
    
    cout << count << endl;
    
    return 0;
}
