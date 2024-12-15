# include <iostream>
# include <cmath>
using namespace std;

/*WAP to print sine series using Taylor expansion*/
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n-1);
}

void sine(float x)
{
    // sine series
    double sum = 0;
    int j = 1;
    int n = 1;
    for (int i = 0; i < 11; i++)
    {
        sum += j * pow(x , n) / fact(n); // summation formula
        j *= -1;    // alternating series
        n += 2;     // only odd powers
    }
    cout << "sin(" << x << ")" << " = " << sum;
}

int main()
{
    sine(1.57);
    return 0;
}