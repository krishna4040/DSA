/*Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N
is an element that appears more than N/2 times in the array.*/
//* Moores voting algorithm
# include <iostream>
using namespace std;

int majorityElement(int arr[], int n)
{
    int res = 0 , count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
            res = 1; count = 1;
    }
    count = 0;
    for (int i = 0; i < n; i++)
        if (arr[res] == arr[i])
            count++;
    if (count <= n/2)
        return -1;
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
