#include <iostream>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	int min = k == 0 ? 0 : n == k ? 0 : 1;

	int x = n / 3;

	int max;
	int r;

	if (k <= x)
	{
		max = 2*k;
	}
	else
	{
		max = 2*x - (k - x) + n % 3;
	}

	cout << min << " " << max << endl;

	return 0;
}