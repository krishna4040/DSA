# include <iostream>
using namespace std;

void dsc(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    dsc(n-1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    dsc(n);
    return 0;
}
