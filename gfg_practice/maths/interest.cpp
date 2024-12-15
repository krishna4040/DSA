# include <iostream>
using namespace std;

/*Compute interset --> SI CI*/
int main()
{
    int p , r , t;
    cin >> p >> t;
    if (p > 10000 && t > 5)
        r = 7.5;
    else
        r = 7;
    float si = p*r*t/100;
    float amount = p + si;
    cout << si << endl;
    cout << amount << endl;

    return 0;
}