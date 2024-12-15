# include "bits/stdc++.h"
using namespace std;

bool isLucky(int n)
{
    static int counter = 2;
    if (counter > n)
        return 1;
    if (n % counter == 0)
        return 0;
    /*calculate next position of input no.variable "next_position" is just for readability of the program we can remove it and update in "n" only */
    int next_position = n - (n / counter);
    counter++;
    return isLucky(next_position);
}

int main()
{
    cout << isLucky(5);
    return 0;
}