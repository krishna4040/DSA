# include "bits/stdc++.h"
using namespace std;

// Kth boom num: Boom numbers are numbers consisting only of digits 2 and 3.
void boomnum(int k)
{
    queue<string> q;
    q.push("");
    int count = 0;
    while (count <= k)
    {
        string s1 = q.front();
        string s2 = s1;     // stroting curr boom before changing
        q.pop();
        q.push(s1.append("2"));
        count++;
        if (count == k)
        {
            cout << s1;
            break;
        }

        q.push(s2.append("3"));
        count++;
        if (count == k)
        {
            cout << s2;
            break;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    boomnum(10);
    return 0;
}