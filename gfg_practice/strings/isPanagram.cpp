# include "bits/stdc++.h"
using namespace std;

// Panagram is a string that contains all letter of english alphabet case do not matter
bool isPanagram(string s)
{
    bool count[256] = {0};

    for (int i = 0; i < s.length(); i++)
        count[s[i]] = true;

    for (int i = 65; i <= 90; i++)
        if (count[i])
            count[i+32] = 1;

    for (int i = 97; i <= 122; i++)
        if (count[i])
            count[i-32] = 1;

    for (int i = 65; i < 90; i++)
        if (!count[i])
            return 0;

    for (int i = 97; i < 122; i++)
        if (!count[i])
            return 0;

    return 1;
}

int main(int argc, char const *argv[])
{
    string s = "Bawds jog flick quartz vex nymph";
    cout << isPanagram(s);
    return 0;
}