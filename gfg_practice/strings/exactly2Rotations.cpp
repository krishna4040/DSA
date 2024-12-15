# include "bits/stdc++.h"
using namespace std;

// Check if s2 is exactly 2 places rotated in s1
int check(string s1 , string s2)
{
    if(s1.length() != s2.length())
        return 0;
    if(s1.length() == 1)
        return (s1 == s2);
    return ((s1+s1).find(s2) == 2 || (s2+s2).find(s1) == 2);
}

int main(int argc, char const *argv[])
{
    string s1 = "fsbcnuvqhffbsaqxwp";
    string s2 = "wpfsbcnuvqhffbsaqx";

    cout << check(s1,s2);

    return 0;
}