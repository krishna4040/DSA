# include <iostream>
# include <cmath>
using namespace std;

/*Given an integer N. Find the number of digits that appear in its factorial.*/
int digitsinfact(int n)
{
    double count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += log10(i);
    }
    return floor(count) + 1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << digitsinfact(n);
    return 0;
}
