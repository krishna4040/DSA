# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

bool isSubseq(const string s1 , const string s2)
{
    int n = s1.length() , m = s2.length();
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (s1[i] == s2[j])
            j++;
    return (j == m);
}

bool issubseq(string s1 , string s2 , int i , int j)
{
    if (j == s2.length())
        return 1;
    if (i == s1.length())
        return 0;
    if (s1[i] == s2[j])
        return issubseq(s1,s2,i+1,j+1);
    else
        return issubseq(s1,s2,i+1,j);
}

int main(int argc, char const *argv[])
{
    string s1 = "ABCD" , s2 = "DA";
    cout << issubseq(s1,s2,0,0);
    return 0;
}