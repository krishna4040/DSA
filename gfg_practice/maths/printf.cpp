# include <iostream>
using namespace std;
// concept: compiler prints in order of L to R but reads value inside printf R to L
int main()
{
    int i = 1;
    printf("%d%d%d" , i , ++i , i++);   // 3 3 1
    return 0;
}