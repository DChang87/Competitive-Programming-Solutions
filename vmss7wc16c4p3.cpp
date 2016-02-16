/*
For a given word in the input file, A, Jeffrey would like to transform it to a new word, B. 
he has three different operations to transform the word.
Jeffrey can…
Delete a character from A using D seconds.
Insert a character into A using I seconds.
Replace a character in A with a new character using R seconds.
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010]; int N,D,I,R; string A,B;
int T(int i,int j){
    if (dp[i][j]!=-1)return dp[i][j];
    //if one string is empty, the only way to match them up is to insert the empty string with the letters of the full string
    if (i==0){
        dp[i][j]=j*I;
        return j*I;
    }
    if (j==0){
        dp[i][j]=i*D;
        return i*D;
    }
    dp[i][j] = T(i-1,j)+D; //delete 
    dp[i][j]= min(dp[i][j],T(i,j-1)+I); //insert
    if (A[i-1]==B[j-1]) dp[i][j]=min(dp[i][j],T(i-1,j-1)); //if last characters are the same, we're good, nothing to do
    dp[i][j]=min(dp[i][j],T(i-1,j-1)+R); //replace
    return dp[i][j];
}
int main()
{
    freopen("7wc4testdata/p3_4.in","r",stdin); freopen("7wc4testdata/p3_4.out","w",stdout);
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>D>>I>>R;
    cin>>A>>B;
    for (int j=0;j<1010;j++){
        for (int k=0;k<1010;k++){
            dp[j][k]=-1;
        }
    }
    cout<<T(A.size(),B.size())<<endl;
    return 0;
}
