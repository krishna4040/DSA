# include <iostream>
using namespace std;

/*Total numbers upto n divisible by a or b*/
int divisibleByaOrb(int n, int a, int b)
//inclusion and exclusion
{
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    return c1+c2-c3;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
