# include <iostream>
# include <algorithm>
using namespace std;

//GCD(LCM (x, y), LCM (x, z)) = LCM(x, GCD(y, z))
int findValue(int x, int y, int z)
{
	int g = __gcd(y, z);
	// Return LCM(x, GCD(y, z))
	return (x*g)/__gcd(x, g);
}

int main()
{
	int x = 30, y = 40, z = 400;
	cout << findValue(x, y, z);
	return 0;
}