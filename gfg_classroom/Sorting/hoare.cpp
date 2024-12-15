# include <iostream>
using namespace std;

int hoare(int arr[] , int l , int h , int p)
{
    swap(arr[l],arr[p]);
    int pivot = arr[p];
    int i = l , j = h;
    while (1)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i >= j)
            return j;
        swap(arr[i],arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    hoare(arr,0,5,2);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}