# include <iostream>
# include <vector>
using namespace std;

/*swicth the even and odd bits of a number*/
unsigned int swapbits(unsigned int x)
{
    unsigned int m = x & 0xaaaaaaaa; // getting even bits
    unsigned int n = x & 0x55555555; // getting odd bits

    m >>= 1;    // shifting even bits to odd
    n <<= 1;    // shifting odd bits to even

    return (n | m); // combining
}

int main(int argc, char const *argv[])
{
    unsigned int a = 23;
    cout << swapbits(a);
    return 0;
}