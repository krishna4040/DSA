# include "bits/stdc++.h"
using namespace std;

vector<string> winner(string arr[],int n)
{
    unordered_map<string,int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    vector<string> ans;
    int res = 0;
    for (auto &&x : m)
        res = max(res,x.second);
    for (auto &&x : m)
    {
        if (x.second == res)
        {
            ans.push_back(x.first);
            ans.push_back(to_string(x.second));
            return ans;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}