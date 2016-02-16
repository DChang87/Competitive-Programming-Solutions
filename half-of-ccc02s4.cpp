/*
A rope bridge traverses a deep gorge. People may cross the bridge in groups, but there is a limit (M) to the size of the 
group. The time taken for a group to cross is determined by the slowest member. You are responsible for safety on the 
bridge and part of your job is to control the groups crossing.
People are waiting in a queue (line); when the previous group has crossed, you tell the next few people they can now cross. 
Groups can be of different sizes; no group can contain more than M people, and the goal is to get everyone over in the shortest 
time, all the time maintaining the order of the people in the queue.
Input
The first line of the input contains an integer M (1 ≤ M ≤ 20). The second line contains Q (1 ≤ Q ≤ 100), the length 
of the queue waiting to cross.
For each person in the queue, a pair of input lines follows. The first of these is the name of the person, and the 
second is that person's individual time to cross the bridge. Recall that a group's crossing time will be the maximum 
crossing time for any individual in the group.
*/
#include<bits/stdc++.h>
using namespace std;
int M,Q;
string names[110]; int times[110]; int groups[110]; int dp[110];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>M>>Q;
    for (int i=0;i<Q;i++){
        cin>>names[i]>>times[i];
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
