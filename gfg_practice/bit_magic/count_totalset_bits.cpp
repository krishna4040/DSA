# include <iostream>
using namespace std;

/*You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).*/
// TC: O(logn)
int setbitcount(int n)
{
    int count = 0;
    while (n)
    {
        n &= n-1;
        count++;
    }
    return count;
}
int countSetBits(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += setbitcount(i);
    return sum;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
