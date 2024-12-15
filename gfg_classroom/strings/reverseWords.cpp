# include "bits/stdc++.h"
using namespace std;

void reverseWords(char *str , int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (str[end] == ' ')
        {
            reverse(str+start,str+end);
            start = end+1;
        }
    }
    reverse(str+start,str+n);
    reverse(str,str+n);
}

int main(int argc, char const *argv[])
{
    char s[] = "welcome here";
    reverseWords(s,12);
    cout << s << endl;
    return 0;
}