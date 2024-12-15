/*Given an array arr[] of size N and two elements x and y, use counter variables to find which element appears most in the array,
x or y. If both elements have the same frequency, then return the smaller element.
Note:  We need to return the element, not its count.*/
# include <iostream>
using namespace std;

int majorityWins(int arr[], int n, int x, int y)
{
    int countx = 0;
    int county = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            countx++;
        if (arr[i] == y)
            county++;
    }
    if (countx > county)
        return x;
    else if (county > countx)
        return y;
    else
    {
        if (x < y)
            return x;
        else
            return y;
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}