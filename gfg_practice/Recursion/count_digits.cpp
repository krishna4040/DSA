# include <iostream>
using namespace std;

int count(int n)
{
    static int c;
    if (n == 0)
        return 1;
    c++;
    count(n/10);
    return c;
}

int main(int argc, char const *argv[])
{
    cout << count(605);
    return 0;
}
