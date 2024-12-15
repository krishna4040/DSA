# include <iostream>
using namespace std;

/*WAP to decide type of triangle*/
int main(int argc, char const *argv[])
{
    int a , b , c;
    (a == b || b == c || c == a) ? (a == b && b == c && c == a) ? puts("i") : puts("e") : puts("s"); // cannot use cout
    return 0;
}
