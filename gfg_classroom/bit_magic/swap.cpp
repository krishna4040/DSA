# include <iostream>
using namespace std;

void swap(int a , int b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout << a << b;
}

int main(int argc, char const *argv[])
{

    return 0;
}
