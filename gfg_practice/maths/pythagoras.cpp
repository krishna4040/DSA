# include <iostream>
using namespace std;

/*Check weather given numbers are pythagorian triplet*/
bool check(int x,int y,int z){
    int a = max(x,max(y,z));
    int b,c;
    if (a==x){b=y;c=z;}
    else if(a==y){b=x;c=z;}
    else{b=x;c=y;}
    if(a*a == b*b+c*c){return 1;}
    else{return 0;}
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
