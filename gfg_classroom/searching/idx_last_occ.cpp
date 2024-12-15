# include <iostream>
using namespace std;

int idxlast(int arr[] , int n , int x)
{
    int l = 0 , h = n-1;
    while (l <= h)
    {
        int m = (l+h)/2;
        if (arr[m] == x)
        {
            if (arr[m]!=arr[m+1] || m == n-1)
                return m;
            else
                l = m+1;
        }
        else if (x > arr[m])
            l = m+1;
        else
            h = m-1;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,10,10,10,20,20,30};
    cout << idxlast(arr,7,20);
    return 0;
}
