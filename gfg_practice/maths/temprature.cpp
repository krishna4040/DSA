# include <iostream>
using namespace std;

/*Given a temperature in celsius C. You need to convert the given temperature to Fahrenheit.*/
long double operator "" _k(long double k) {return k - 273.15;}
long double operator "" _f(long double f) {return (f-32)*(5/9);}
long double operator "" _c(long double c) {return c;}

int main(int argc, char const *argv[])
{
    int T = 32.0_f;
    cout << T;
    return 0;
}
