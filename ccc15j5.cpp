//recursion with tracking

#include<bits/stdc++.h>
using namespace std;
int N,K;
int dp[300][300][300];
int recurse(int n,int k, int MIN){
    if (dp[n][k][MIN]==0){
        if (n==k){
            dp[n][k][MIN]=1;
        }
        if (k==1){
            dp[n][k][MIN]=1;
        }
        else{
            int total=0;
            for (int i=MIN;i<(n/k)+1;i++){
                total += recurse(n-i,k-1,i);
            }
            dp[n][k][MIN]=total;
        }
    }
    return dp[n][k][MIN];
}
int main()
{
    cin>>N>>K;
    cout<<recurse(N,K,1);

}
