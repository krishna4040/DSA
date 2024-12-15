# include <iostream>
using namespace std;

/*give the count for maximum consecutive ones in a number*/
int longest1count(int n)
{
    // resetting count approach
    int mxcount = 0 , count = 0;
    while (n)
    {
        if (n & 1)
        {
            count++;
            mxcount = max(mxcount , count);
            n >>= 1;
            continue;
        }
        else
        {
            count = 0;
            n >>=1;
        }
    }
    return mxcount;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << longest1count(n);
    return 0;
}