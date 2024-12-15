/*Given n integer ranges, the task is to find the maximum occurring integer in these ranges. 
If more than one such integer exists, find the smallest one. The ranges are given as two arrays L[] and R[].
L[i] consists of starting point of range and R[i] consists of corresponding end point of the range.*/
# include <iostream>
using namespace std;

int maxOccured(int L[], int R[], int n, int maxx)
{
    int frq[maxx] = {0};
    for (int i = 0; i < n; i++)
    {
        frq[L[i]]++;
        frq[R[i]+1]--;
    }
    int res = 0;
    for (int i = 0; i < maxx; i++)
    {
        frq[i] = frq[i-1] + frq[i];
        if (frq[i] > frq[res])
        {
            res = i;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}