# include <iostream>
using namespace std;

// Binary addition
int sumbin(int bin1,int bin2){
    int ans=0;
    int prevcarry=0;
    while(bin1>0 && bin2>0){
        if(bin1%2==0 && bin2%2==0)
        {
            ans=ans*10+prevcarry;prevcarry=0;
        }
        else if((bin1%2==0 && bin2%2==1)||(bin1%2==1 && bin2%2==0))
        {
            if(prevcarry==1){ans=ans*10+0;prevcarry=1;}
            else{ans=ans*10+1;prevcarry=0;}
        }

        else{ans=ans*10+prevcarry;}

        bin1 /= 10;
        bin2 /= 10;
    }
    while(bin1>0){
        if(prevcarry==1){ans=ans*10+0;prevcarry=1;}
        else{ans=ans*10+1;prevcarry=0;}
    }

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
