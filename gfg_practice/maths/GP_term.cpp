# include <iostream>
# include <cmath>
using namespace std;

/*Given the first 2 terms A and B of a Geometric Series. The task is to find the Nth term of the series.*/
double GP(int a , int b , int n)
{
// APterm , GPterm , APsum , GPsum
    double r = (double)b / (double)a;
    double t = a * pow(r , n-1);
    return t;
}

int main(int argc, char const *argv[])
{
    int a , b , n;
    cin >> a >> b >> n;
    cout << GP(a , b , n);
    return 0;
}