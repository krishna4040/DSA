# include <iostream>
using namespace std;

/*print fibonacci series*/
void fib(int n)
{
    int t1 = 0;
    int t2 = 1;
    while (n)
    {
        int nextterm = t1 + t2;
        cout << t1;
        t1 = t2;
        t2 = nextterm;
        n--;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    fib(n);
    return 0;
}
