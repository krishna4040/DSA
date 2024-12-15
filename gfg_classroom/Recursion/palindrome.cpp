# include <iostream>
using namespace std;

bool ispalindrome(string str , int s , int e)
{
    if (s >= e)
        return 1;
    return (str[s] == str[e] && ispalindrome(str,s+1,e-1));
}

int main(int argc, char const *argv[])
{
    cout << ispalindrome("krishna" , 0 , 6);
    cout << ispalindrome("gfg" , 0 , 2);

    return 0;
}