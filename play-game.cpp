/*
You and your friend decide to play a game using a stack consisting of N bricks. In this game, you can 
alternatively remove 1, 2 or 3 bricks from the top, and the numbers etched on the removed bricks are added 
to your score. You have to play so that you obtain the maximum possible score. It is given that your friend 
will also play optimally and you make the first move.
*/
#include<bits/stdc++.h>
using namespace std;
int N;
long long coins[1010]; long long dp[1010];
long long dp1(int i){
    if (i>=N)return 0;
    if (dp[i]==-1){
        dp[i]=max(coins[i]+min(dp1(i+2),min(dp1(i+3),dp1(i+4))),dp[i]);
        dp[i]=max(coins[i]+coins[1+i]+min(dp1(i+3),min(dp1(i+4),dp1(i+5))),dp[i]);
        dp[i]=max(coins[i]+coins[1+i]+coins[2+i]+min(dp1(i+4),min(dp1(i+5),dp1(i+6))),dp[i]);
    }
    return dp[i];
}
int T;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>T;
    for (int jj=0;jj<T;jj++){
        cin>>N;
        for (int i=0;i<N;i++) cin>>coins[i];
        for (int i=0;i<N;i++) dp[i]=-1;
        dp[N-1] = coins[N-1];
        dp[N-2] = coins[N-2]+dp[N-1];
        dp[N-3] = coins[N-3]+dp[N-2];
        cout<<dp1(0)<<endl;
    }
    return 0;
}
