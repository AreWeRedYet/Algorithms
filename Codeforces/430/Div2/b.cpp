#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int radius, d, n;

    cin >> radius >> d >> n;

    vector<int> x(n), y(n), r(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        double dist = sqrt(x[i]*x[i] + y[i]*y[i]);
        if (dist - r[i] >= radius - d && dist + r[i] <= radius)
        {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}