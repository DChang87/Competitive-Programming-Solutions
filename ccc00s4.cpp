/*
Roberta the Robot plays a perfect game of golf. When she hits the golf ball it always goes directly 
towards the hole on the green, and she always hits exactly the distance that is specified for the club. 
Each such action is known as a stroke, and the object of golf is to hit the ball from the tee to the hole 
in the fewest number of strokes. Roberta needs a program to select the best combination of clubs to reach 
the hole in the fewest strokes. She also needs to decide if the task is impossible, in which case she 
graciously acknowledges the loss. Roberta can carry up to 32 clubs, and the total distance from the tee 
to the hole does not exceed 5280 metres.
Input
The first line of input gives the distance from the tee to the hole, an integral number of metres 
between 1 and 5280. The next line states the number of clubs, between 1 and 32. For each club, a 
line follows giving the distance, in metres, that the club will hit the ball, an integer between 1 
and 100. No two clubs have the same distance.
*/
#include<bits/stdc++.h>
using namespace std;
int D,C;
int clubs[40],dp[5350];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>D>>C;
    for (int i=0;i<C;i++) cin>>clubs[i];
    for (int i=0;i<=D;i++) dp[i]=100000;
    dp[0]=0;
    for (int i=1;i<=D;i++){
        for (int j=0;j<C;j++){
            if (i-clubs[j]<0)continue;
            dp[i] = min(dp[i],dp[i-clubs[j]]+1);
        }
    }
    if (dp[D]==100000) cout<<"Roberta acknowledges defeat."<<endl;return 0;
    cout<<"Roberta wins in "<<dp[D]<<" strokes."<<endl; return 0;
}

