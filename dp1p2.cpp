/*
There are a bunch of coins on a table, laid out in a straight line.
Each coin has a (positive) value from 1 to 1000. Now, you're going to play a game with a friend.
At every turn, you must remove a coin from one end of the line.
Turns alternate, so your friend goes immediately after you're done.
The game ends when there are no coins remaining.
An example game:
The coins start like this:                  4 4 9 4
You always go first, so you take the 4 from the left side:          4 9 4
Your friend takes any of the 4s (it doesn't matter)             9 4
Now you can take the 9, and your friend takes the remaining 4.
Your score, in this case, is 4+9 = 13.  (In this case you can always beat your friend.)
Find the maximum possible score you can achieve.
*/
#include<bits/stdc++.h>
using namespace std;
int N;  int coins[1010];  int dp[1010][1010];
int dp1(int i,int j){
    if (dp[i][j]==-1) dp[i][j]=max(coins[i]+min(dp1(i+1,j-1),dp1(i+2,j)),min(dp1(i,j-2),dp1(i+1,j-1))+coins[j]);
    return dp[i][j];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++) cin>>coins[i];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
    for (int i=0;i<N;i++) dp[i][i]=coins[i];
    for (int i=0;i<N-1;i++) dp[i][i+1]=max(coins[i],coins[i+1]);
    for (int i=0;i<N-2;i++) dp[i][i+2]=max(coins[i+2]+min(coins[i],coins[i+1]),coins[i]+min(coins[i+1],coins[i+2]));
    cout<<dp1(0,N-1)<<endl;
    return 0;
}
