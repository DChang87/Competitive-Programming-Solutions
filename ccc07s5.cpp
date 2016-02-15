#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for (int i=0;i<N;i++){
        int n,k,w;
        cin>>n>>k>>w;
        int balls[n];
        int sum[n];
        int temps=0;
        for (int j=0;j<n;j++){
            cin>>balls[j];
            sum[i]=0;
        }
        for (int j=0;j<w;j++){
            temps+=balls[j];
        }
        sum[0]=temps;
        for (int j=1;j<n-w+1;j++){
            temps=temps-balls[j-1]+balls[j+w-1];
            sum[j]=temps;
        }
        for (int j=n-w+1;j<n;j++){
            temps-=balls[j-1];
            sum[j]=temps;
        }
        long long int dp[k+1][n];
        for (int j=1;j<n;j++){
            dp[0][j]=0;
        }
        for (int j=1;j<=k;j++){
            for (int m=1;m<n;m++){
                dp[j][m]=-1;
            }
        }
        for (int j=1;j<=k;j++){
            for (int m=n-1;m>=0;m--){
                if (m>=n-w){
                    dp[j][m]=sum[m];
                }
                else{
                    dp[j][m] = max(sum[m]+dp[j-1][m+w],dp[j][m+1]);
                }

            }
        }
        cout<<dp[k][0]<<endl;;
    }
}
