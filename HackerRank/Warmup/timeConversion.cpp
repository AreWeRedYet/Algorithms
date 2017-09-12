#include <iostream>
#include <vector>
#include <string>

using namespace std;

string timeConversion(string s) {
    bool isAM = s.substr(s.size() - 2, 2) == "AM";
    string hour = s.substr(0, 2);
    
    if (hour != "12") {
        if (!isAM) {
            hour = to_string(stoi(hour) + 12);
        }
    }
    else {
        if (isAM) {
            hour = "00";
        }
    }
    
    return hour + s.substr(2, s.size() - 4);
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}

