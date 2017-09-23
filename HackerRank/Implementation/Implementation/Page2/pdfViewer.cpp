#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int alphabetLength = 26;
    
    vector<int> letterHeight(alphabetLength);
    for (int i = 0; i < alphabetLength; i++) {
        cin >> letterHeight[i];
    }
    
    string word;
    cin >> word;
    
    int maxLetterSize = letterHeight[word[0] - 'a'];
    for (int i = 1; i < word.length(); i++) {
        maxLetterSize = max(maxLetterSize, letterHeight[word[i] - 'a']);
    }
    
    cout << maxLetterSize * word.length() << endl;
    
    return 0;
}
