# include <iostream>
using namespace std;

int countmerge(int arr[] , int l , int m , int h)
{
    int n1 = m-l+1 , n2 = h-m;
    int left[n1] , right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l+i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[m+1+i];

    int i = 0 , j = 0 , k = l ,res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
            res += n1-i;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

int countInversion(int arr[] , int l , int h)
{
    int res = 0;
    if (l < h)
    {
        int m = (l+h)/2;
        res += countInversion(arr,l,m);
        res += countInversion(arr,m+1,h);
        res += countmerge(arr,l,m,h);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,4,1,3,5};
    cout << countInversion(arr,0,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    
    return 0;
}