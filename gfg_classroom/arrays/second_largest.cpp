# include <iostream>
using namespace std;

int secondlargest(int arr[] , int n)
{
    int res = -1 , largest = 0;     //res: second largest
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
            if (res == -1 || arr[i] > arr[res])
                res = i;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,10,10,10};
    cout << secondlargest(arr,4);
    return 0;
}
