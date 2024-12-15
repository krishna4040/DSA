# include "bits/stdc++.h"
using namespace std;

bool isrotated(string s1 , string s2)
{
    if (s1.length() != s2.length())
        return 0;
    string concat = s1 + s1;
    if (concat.find(s2) == string::npos)
        return -1;
    return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}