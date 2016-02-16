/*
Frank has made it to a Food Basics! Without causing property damage exceeding $1000! There he meets Jeffrey 
(since grocery stores don't have roads) and he agrees to help Frank buy some apples. You must also help Frank buy some apples.
The Food Basics that Frank is visiting has N different types of apples, and he can take as much as he can 
of each type. However, there are some restrictions: Frank has only R dollars to spend on apples, and his 
car can only hold S volume, excluding Frank's volume (Frank obviously isn't giving Jeffrey a ride, as cars drive on roads).
Frank also likes some types of apples more than others, and he assigns a value V to each type of apple. 
Frank likes apples with larger values.
Jeffrey and Frank would like to buy apples in such a way so that he can maximise the total sum of all values 
of apples. Help them calculate it!
*/
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
