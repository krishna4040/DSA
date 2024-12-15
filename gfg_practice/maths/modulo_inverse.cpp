# include <iostream>
using namespace std;

int moduloinverse(int a , int m)
{
    if (a % m == 0)
    {
        return -1;
    }
    for (int i = 1; i < m; i++)
    {
        if ((a * i) % m == 1)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int a , m;
    cin >> a >> m;
    cout << moduloinverse(a , m);
    return 0;
}
