# include <iostream>
using namespace std;

/*Given an integer N. The task is to return the position of first set bit found from the right side in the binary
representation of the number.*/
int firstsetbit(int n)
{
    if(n==0)
        return 0;
    int count = 0;
    while(n)
    {
        count++;
        if(n & 1)
            return count;   // we return 1 << count to get decimal equivalent
        n >>= 1;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << firstsetbit(n);
    return 0;
}
