#include<bits/stdc++.h>
using namespace std;
int M,Q;
string names[110];
int times[110];
int groups[110];
int dp[110];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>M>>Q;
    for (int i=0;i<Q;i++){
        cin>>names[i];
        cin>>times[i];
    }
    memset(dp,1000000,sizeof dp);
    dp[0]=times[0];
    groups[0]=1;
    for (int i=1;i<Q;i++){
        int MAX = times[i];
        for (int j=0;j<M;j++){
            if (i-j-1<0)break;
            MAX = max(MAX,times[i-j]);
            if (MAX + dp[i-j-1]<dp[i]){
                dp[i] = dp[i-j-1]+MAX;
                //cout<<i<<" "<<j<<endl;
                groups[i] = j+1;
                for (int k=1;k<=j;k++){
                    groups[i-k]=0;
                }
            }
        }
    }
    cout<<"Total Time: "<<dp[Q-1]<<endl;

    return 0;
}

