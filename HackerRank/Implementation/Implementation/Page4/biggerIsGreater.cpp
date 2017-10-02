#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string nextBigger(string &word) {
    for (unsigned long i = word.length() - 1; i > 0; i--) {
        if (word[i - 1] < word[i]) {
            string::reverse_iterator it = find_if(word.rbegin(), word.rend(), [&word, &i] (char c) {
                return c > word[i - 1];
            });
            
            if (it == word.rend()) {
                throw "Error";
            }
            
            swap((*it), word[i - 1]);
            reverse(word.begin() + i, word.end());
            
            return word;
        }
    }
    
    return "no answer";
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string word;
        cin >> word;
       
        cout << nextBigger(word) << endl;
    }
    
    return 0;
}
