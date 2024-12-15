# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

bool isRotation(string s1 , string s2)
{
    string s = s1 + s1;
    if (s.find(s2) != string::npos)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    string s1 = "ABAB";
    string s2 = "BABA";
    cout << isRotation(s1,s2);
    return 0;
}