# include <iostream>
using namespace std;

int maxAppearing(int larr[] , int rarr[] , int n)
{
    int frq[101] = {0};
    for (int i = 0; i < n; i++)
    {
        frq[larr[i]]++;
        frq[rarr[i]+1]--;
    }

    int psum[100];
    psum[0] = frq[0];
    for (int i = 0; i < n; i++)
        psum[i] = frq[i] + psum[i-1];
    
    int res = 0;
    for (int i = 0; i < 100; i++)
        if (psum[i] > psum[res])
            res = i;
    return res;
}

int main(int argc, char const *argv[])
{
    int larr[] = {1,2,5,15};
    int rarr[] = {5,8,7,18};
    cout << maxAppearing(larr,rarr,5);
    return 0;
}
