# include "bits/stdc++.h"
using namespace std;

bool isAnagramPresent(string txt , string pat)
{
    if(txt.find(pat) != string::npos)
        return 1;
    

}

int main(int argc, char const *argv[])
{
    string txt = "geeksforgeeks";
    string pat = "frog";
    cout << isAnagramPresent(txt,pat);
    return 0;
}