#include<iostream>
using namespace std;
int main()
{
    int N,R,S;
    cin>>N>>R>>S;
    string names[N];
    int apples[N][3];
    int dp[R+1][S+1][N+1];
    for (int i=0;i<=R;i++)
    for (int j=0;j<=S;j++)
    for (int k=0;k<=N;k++)
        dp[i][j][k]=0;
    string name;
    int val,cost,vol;
    for (int i=0;i<N;i++){
        cin>>name>>val>>cost>>vol;
        names[i]=name;
        apples[i][0]=val;
        apples[i][1]=cost;
        apples[i][2] = vol;
    }
    
    for (int sac=1;sac<=R;sac++){ //cost per sac
        for (int Vol=1;Vol<=S;Vol++){
            for (int app=0;app<N;app++){
                if (sac>=apples[app][1] && Vol>=apples[app][2]){
                    if (dp[sac-apples[app][1]][Vol-apples[app][2]][0]+apples[app][0]>=dp[sac][Vol][0]){
                        dp[sac][Vol][0] = dp[sac-apples[app][1]][Vol-apples[app][2]][0]+apples[app][0];
                        for (int app2=1;app2<=N;app2++){
                            dp[sac][Vol][app2]=dp[sac-apples[app][1]][Vol-apples[app][2]][app2];
                        }
                        dp[sac][Vol][app+1]++;
                    }
                }
            }
        }

    }
    cout<<dp[R][S][0]<<endl;
    for (int i=1;i<=N;i++){
        cout<<names[i-1]<<" "<<dp[R][S][i]<<endl;
    }
}
