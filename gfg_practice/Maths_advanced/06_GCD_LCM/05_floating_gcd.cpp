#include <bits/stdc++.h>
using namespace std;

double gcd(double a, double b)
{
	if (a < b)
		return gcd(b, a);

	// base case
	if (fabs(b) < 0.001)
		return a;
	else
		return (gcd(b, a - floor(a / b) * b));
}

int main()
{
	double a = 1.20, b = 22.5;
	cout << gcd(a, b);
	return 0;
}
