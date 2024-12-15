# include <iostream>
using namespace std;

int setcount(int n)
{
    int count = 0;
    while (n)
    {
        // Brian kernighans algorithm
        // making last setbit zero
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << setcount(n);
    return 0;
}