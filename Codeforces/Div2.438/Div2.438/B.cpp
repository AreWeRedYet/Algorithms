#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool tryT1T2Path(vector<int> &angles, int t1Angle, int t2Angle) {
    bool success = true;
    
    for (int i = 0; i < angles.size(); i++) {
        if (angles[i] > t1Angle && angles[i] < t2Angle) {
            success = false;
            break;
        }
    }
    
    return success;
}

int main()
{
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    
    int hAngle = (h * 360 / 12) % 360;
    int mAngle = (m * 360 / 60) % 360;
    int sAngle = (s * 360 / 60) % 360;
    
    vector<int> angles = { hAngle, mAngle, sAngle };
    
    int t1Angle = (t1 * 360 / 12) % 360;
    int t2Angle = (t2 * 360 / 12) % 360;
    
    t1Angle = min(t1Angle, t2Angle);
    t2Angle = max(t1Angle, t2Angle);
    
    if (tryT1T2Path(angles, t1Angle, t2Angle)) {
        cout << "YES" << endl;
        return 0;
    }
    else if (tryT1T2Path(angles, t2Angle, 360) && tryT1T2Path(angles, 0, t1Angle) && (t1Angle == 0 || (hAngle != 0 && mAngle != 0 && sAngle != 0))) {
        cout << "YES" << endl;
        return 0;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}
