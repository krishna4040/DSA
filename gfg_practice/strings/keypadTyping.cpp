# include "bits/stdc++.h"
using namespace std;

// given a string return its corrosponding num formed on pressing str on keypad
string keypadTyping(string s , int n)
{
    unordered_map<string,string> m = {{"abc","2"},{"def","3"},{"ghi","4"},{"jkl","5"},{"mno","6"},{"pqrs","7"},{"tuv","8"},{"wxyz","9"}};
    string res = "";
    for (int i = 0; i < n; i++)
    {
        for (auto &&x : m)
        {
            for (auto &&c : x.first)
            {
                if (s[i] == c)
                {
                    res += x.second;
                    break;
                }
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "geeksforgeeks";
    cout << keypadTyping(s,13);
    return 0;
}