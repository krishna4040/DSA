# include <iostream>
using namespace std;

int max1(bool arr[] , int n)
{
    int count = 0 , maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            count++;
            maxcount = max(count,maxcount);
        }
        else
            count = 0;
    }
    return maxcount;
}

int main(int argc, char const *argv[])
{
    bool arr[] = {0,1,1,0,1,0};
    cout << max1(arr,6);
    return 0;
}