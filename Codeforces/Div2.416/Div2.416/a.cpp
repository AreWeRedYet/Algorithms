#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int candy = 1;
    bool isVladikTurn = true;
    
    while (a >= 0 && b >= 0)
    {
        if (isVladikTurn)
        {
            a = a - candy;
        }
        else
        {
            b = b - candy;
        }
        
        candy++;
        isVladikTurn = !isVladikTurn;
    }
    
    if (a < 0)
    {
        cout << "Vladik";
    }
    else
    {
        cout << "Valera";
    }
    
    return 0;
}

