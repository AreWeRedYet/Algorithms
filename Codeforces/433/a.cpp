#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int r;
	while (a % b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return b;
}

int main()
{
	int n;
	cin >> n;

	int denominator = n/2 + 1;
	int enumerator = n - denominator;

	while (gcd(denominator, enumerator) != 1)
	{
		denominator++;
		enumerator--;
	}

	cout << enumerator << " " << denominator << endl;
	

	return 0;
}