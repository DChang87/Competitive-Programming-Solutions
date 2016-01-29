#include<bits/stdc++.h>
using namespace std;
int N;
int rating[100010];
int dp[100010];
int incr[100010];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>rating[i];
    }
    for (int i=0;i<N;i++){
        dp[i]=1;
    }
    incr[N-1]=1;
    for (int i=N-2;i>=0;i--){
        if (rating[i]>rating[i+1]){
            incr[i] = incr[i+1]+1;
        }
        else{
            incr[i]=1;
        }
    }
    for (int i=1;i<N;i++){

        if (rating[i]>rating[i-1] && incr[i]<=incr[i-1]){ //new increment

            int ori_count=incr[i];
            incr[i]=incr[i-1]+1;
        }
    }
    int sum=0;
    for (int i=0;i<N;i++){
        //cout<<incr[i]<<endl;
        sum += incr[i];
    }
    cout<<sum<<endl;
    return 0;
}

