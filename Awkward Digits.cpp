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
