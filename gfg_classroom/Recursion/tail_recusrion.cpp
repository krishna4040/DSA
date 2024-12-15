# include <iostream>
using namespace std;

// understanding tail recursion in tail recursive function
void dsc(int n)
{
    start:    
        if (n == 0)
        {
            return;
        }
        cout << n << " ";
        n -= 1;
        goto start;
}

// converting into tail recrsion
void asc(int n , int k)
{
    if (n == 0)
        return;
    cout << k << " ";
    asc(n-1 , k+1);
}

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n-1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    asc(n,1);
    return 0;
}
