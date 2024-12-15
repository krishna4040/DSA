# include <iostream>
# include <algorithm>
using namespace std;

void merge_sorted(int a[] , int b[] , int n , int m)
{
    int i = 0 , j = 0;
    while (i <= n || j <= m)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << b[j] << " ";
        j++;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {10,15,20};
    int b[] = {5,6,6,15};
    merge_sorted(a,b,3,4);
    return 0;
}