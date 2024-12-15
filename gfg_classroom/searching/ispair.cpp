# include <iostream>
using namespace std;

bool ispair(int arr[] , int n , int x , int s)
{
    // Two pointer approach
    int i = s , j = n-1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return 1;
        else if (arr[i] + arr[j] > x)
            j--;
        else
            i++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,2,4};
    cout << ispair(arr,3,6,0);
    return 0;
}