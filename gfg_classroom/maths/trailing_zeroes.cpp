# include <iostream>
using namespace std;

int trail(int n)
{
    int count = 0;
    for (int i = 5; i <= n; i+=5)
        count += n / i;
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << trail(n);

    return 0;
}