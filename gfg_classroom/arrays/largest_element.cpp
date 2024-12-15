# include <iostream>
using namespace std;

int largest(int arr[] , int n)
{
    int res = 0;    //res: largest assumed to be first element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[res])
            res = i;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,5,5};
    cout << largest(arr,5);
    return 0;
}
