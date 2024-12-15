# include <iostream>
# include <cmath>
using namespace std;

void powerset(string s)
{
    int n = s.length();
    int m = 1 << n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) // setting n  bits for each integer from 0 to m-1
            if (i & (1 << j))
                cout << s[j];
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    powerset(s);
    return 0;
}
