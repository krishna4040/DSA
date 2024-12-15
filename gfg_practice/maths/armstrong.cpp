# include <iostream>
using namespace std;

/*Check weather an integer is an armstrong number*/
bool isarmstrong(int n)
{
    int temp = n;
    int sum = 0;
    while (temp)
    {
        int digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }
    if (sum == n)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
