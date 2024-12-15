# include "bits/stdc++.h"
using namespace std;

/*Given a string S consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters 
separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase 
character after being sorted and vice versa.*/
void caseSorting(string &s)
{
    string upper , lower;
    for(char c : s)
    {
        if (isupper(c))
            upper += c;
        else
            lower += c;
    }
    sort(upper.begin(),upper.end());
    sort(lower.begin(),lower.end());

    int i = 0 , j = 0;
    for (int k = 0; k < s.length(); k++)
    {
        if (isupper(s[k]))
            s[k] = upper[i++];
        else
            s[k] = lower[j++];
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}