#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long l,r,x,y,k;

	cin >> l >> r >> x >> y >> k;

	long long minExp = k * x;
	long long maxExp = k * y;

	long long intersectLeft = max(minExp, l);
	long long intersectRight = min(maxExp, r);

	long long diff = intersectRight - intersectLeft;

	long long div = intersectLeft % k;

	if (diff >= 0 && (k-div <= diff || div == 0))
	{
		cout << "YES" << endl;
	
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}