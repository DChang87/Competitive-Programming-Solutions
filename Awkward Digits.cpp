//base conversion, storing digits as char
/*
Bessie the cow is just learning how to convert numbers between different
bases, but she keeps making errors since she cannot easily hold a pen
between her two front hooves.  
Whenever Bessie converts a number to a new base and writes down the result,
she always writes one of the digits wrong.  For example, if she converts
the number 14 into binary (i.e., base 2), the correct result should be
"1110", but she might instead write down "0110" or "1111".  Bessie never
accidentally adds or deletes digits, so she might write down a number with
a leading digit of "0" if this is the digit she gets wrong.
Given Bessie's output when converting a number N into base 2 and base 3,
please determine the correct original value of N (in base 10). You can
assume N is at most 1 billion, and that there is a unique solution for N.*/
#include <bits/stdc++.h>
using namespace std;
int convertFromBaseN(char *s, int n){
    int len = strlen(s),tot=0,fact=1;
    while (len)
    {
        len--;
        tot+=(s[len]-'0')*fact;
        fact*=n;
    }
    return tot;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    char A[100],B[100];
    cin>>A>>B;
    int lenA,lenB;
    lenA = strlen(A);
    lenB = strlen(B);
    for (int i=0;i<lenA;i++){
        for (int j=0;j<lenB;j++){
            for (int k=1;k<=2;k++){
                A[i] = (A[i]-'0'+1)%2+'0';
                B[j] = (B[j]-'0'+k)%3+'0';
                if (convertFromBaseN(A,2)==convertFromBaseN(B,3)){
                    cout<<convertFromBaseN(A,2)<<endl;
                    return 0;
                }
                A[i] = (A[i]-'0'+1)%2+'0';
                B[j] = (B[j]-'0'-k+3)%3+'0';
            }
        }
    }
}
