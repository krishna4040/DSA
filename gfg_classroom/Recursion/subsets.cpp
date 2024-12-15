# include <iostream>
using namespace std;

void subset(string s , string curr = "" , int i = 0)
{
    if (i == s.length())
    {
        cout << curr << " ";
        return;
    }
    // take
    subset(s,curr+s[i],i+1);
    // not take
    subset(s,curr,i+1);
}

int main(int argc, char const *argv[])
{
    subset("ABC");
    return 0;
}
