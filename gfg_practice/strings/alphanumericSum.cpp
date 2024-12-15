# include "bits/stdc++.h"
using namespace std;

int getsum(string s)
{
    int sum = 0;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        while (s[i] >= 48 && s[i] <= 57)
        {
            str += s[i];
            i++;
        }
        int x = stoi(str);
        sum += x;
        str = "0";
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string s = "1abc23";
    cout << getsum(s);
    return 0;
}