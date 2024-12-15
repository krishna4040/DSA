# include <iostream>
using namespace std;
/*
* every element from 1 - max(arr) are present
* 1 <= max(Arr) <= n-1
* find the only repeating element*/

// Getlinks ---> Get first node of cycle
int getRepeating(int arr[] , int n)
{
    int slow = arr[0] , fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,2,3,4,2};
    cout << getRepeating(arr,6);
    return 0;
}