# include <iostream>
using namespace std;

/*You are given an interger I, find the absolute value of the interger I*/
int abs(int n)
{
    if (n > 0)
        return n;
    else
        return -1 * n;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << abs(n);
    return 0;
}