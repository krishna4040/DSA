# include "bits/stdc++.h"
using namespace std;

bool areAnagram(string s1 , string s2)
{
    unordered_map<char,int> m1;
    for (int i = 0; i < s1.length(); i++)
        m1[s1[i]]++;
    unordered_map<char,int> m2;
    for (int i = 0; i < s2.length(); i++)
        m2[s2[i]]++;
    for (auto &&i : m1)
        if (m2.find(i.first) == m2.end() || m2[i.first] != i.second)
            return 0;
    for (auto &&i : m2)
        if (m1.find(i.first) == m1.end() || m1[i.first] != i.second)
            return 0;
    return 1;
}


bool anagram(string s1 , string s2)
{
    if (s1.length() != s2.length())
        return 0;
    int count[256] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    string s1 = "aaabc" , s2 = "abaqa";
    cout << areAnagram(s1,s2);
    return 0;
}