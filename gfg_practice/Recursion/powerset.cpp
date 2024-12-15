/*You are given a string. You need to print the lexicographically sorted power-set of the string.*/
# include <iostream>
# include <vector>
using namespace std;

void powerset(string s)
{
    int n = s.length();
    int m = 1 << n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << s[j] << " ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    powerset("ABC");
    return 0;
}
