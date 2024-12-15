# include <iostream>
using namespace std;

int count(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}