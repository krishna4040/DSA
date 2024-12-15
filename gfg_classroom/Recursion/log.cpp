# include <iostream>
using namespace std;

int log(int n)
{
    if (n == 1)
        return 0;
    else
        return 1 + log(n/2);
}

int main(int argc, char const *argv[])
{
    cout << log(16);
    return 0;
}
