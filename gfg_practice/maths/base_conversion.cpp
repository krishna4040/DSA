# include <iostream>
# include <cmath>
using namespace std;

int reverse(int n){
    string s = to_string(n);
    string r;
    int j = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        r[j] = s[i];
        j++;
    }
    int rev = stoi(r);
    return rev;
}
int countdigits(int num){
    string s = to_string(num);
    return s.length();
}
//Number system conversion

//*other bases to decimal
//?(2)--->(10)
int binarytodecimal(int binary){
    int ans = 0;
    int lastdigit;
    int bin = binary;
    for(int i=0;i<countdigits(binary);i++){
        lastdigit = bin % 10;
        ans = ans + lastdigit*(1 << i);
        bin /= 10;
    }
    return ans; 
}
//?(8)--->(10)
int octaltodecimal(int octal){
    int ans=0;
    int x=1;
    while (octal>0)
    {
        int y = octal%10;
        ans += x*y;
        x *= 8;
        octal /= 10;
    }
    return ans;
}
//?(16)--->(10)
int hexadecimaltodecimal(string hexa){
    int ans=0;
    int x=1;
    int s=hexa.size();
    for(int i=s-1;i>=0;i--){
        if(hexa[i]>='0' && hexa[i]<='9'){
            ans += x*(hexa[i]-'0');
        }
        else if(hexa[i]>='A' && hexa[i]<='F'){
            ans += x*(hexa[i]-'A'+10);
        }
        x *= 16;
    }   
    return ans;
}

//*decimal to other bases
//?(10)--->(2)
int decimaltobinary(int decimal){
    while (decimal)
    {
        cout << (decimal & 1);
        decimal >>= 1;
    }
}
//?(10)--->(8)
int decimaltooctal(int decimal){
    int ans=0;
    int remainder;
    while (decimal>0){
        remainder = decimal% 8;
        ans = ans*10 + remainder;
        decimal /= 8;
    }
    return reverse(ans);
}
//?(10)--->(16)
string decimaltohexadecimal(int decimal){
    int x=1;
    string ans="";
    while(x<=decimal){x*=16;}
    x /= 16;
    while(x>0){
        int lastdigit = decimal/x;
        decimal -= lastdigit*x;
        x /= 16;

        if(lastdigit<=9){ans=ans+to_string(lastdigit);}
        else{char c='A'+lastdigit -10;ans.push_back(c);}
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 748488;
    cout << reverse(n);
    return 0;
}