#include<bits/stdc++.h>
using namespace std;
int D,C;
int clubs[40];
int dp[5350];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>D;
    cin>>C;
    for (int i=0;i<C;i++){
        cin>>clubs[i];
    }
    for (int i=0;i<=D;i++){
        dp[i]=100000;
    }
    dp[0]=0;
    for (int i=1;i<=D;i++){
        for (int j=0;j<C;j++){
            if (i-clubs[j]<0)continue;
            dp[i] = min(dp[i],dp[i-clubs[j]]+1);
        }
    }
    if (dp[D]==100000){
        cout<<"Roberta acknowledges defeat."<<endl;return 0;
    }
    cout<<"Roberta wins in "<<dp[D]<<" strokes."<<endl;
    return 0;
}

