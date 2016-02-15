//suplerplumber


#include<bits/stdc++.h>
using namespace std;

int m,n;
char MAP[110][110];
int intMap[110][110];
int dp[110][110];
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    cin>>m>>n;
    while (m!=0 && n!=0){
        for (int i=0;i<m;i++){
            cin>>MAP[i];
        }
        //convert each spot from char to int
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                dp[i][j]=-10;
                if (MAP[i][j]=='.') intMap[i][j]=0;
                else if (MAP[i][j]=='*') intMap[i][j]=-10;
                else{ intMap[i][j] = MAP[i][j]-'0';  }
            }
        }
        dp[m-1][0] = intMap[m-1][0]; //the position where the plumber starts is how much he will have when he starts
        //iterate through the first column (row by row) where the plumber starts, from the bottom of the column up
        for (int i=m-2;i>=0;i--){
            if (MAP[i][0]=='*'){
              //once the plumber hits a wall, he cannot go up any more
                break;
            }
            dp[i][0]= dp[i+1][0]+intMap[i][0];
        }
        for (int i=1;i<n;i++){
          //going colmn by column to trace the plumber's path
            for (int j=0;j<m;j++){
              //go from top to bottom of that column
                if (dp[j][i-1]!=-10){
                    //can move from the left
                    int temp = dp[j][i-1];
                    for (int k=j;k<m;k++){
                      //iterate to the bottom of the column, if there's a wall, the plumber must stop
                        if (intMap[k][i]==-10){
                            break;
                        }
                        //otherwise, the plumber continues to add up and save the amount that he gets for every step
                        temp += intMap[k][i];
                        dp[k][i] = max(dp[k][i],temp);
                    }
                }
            }
            for (int j=m-1;j>=0;j--){
            //iterate now from bottom up
                if (dp[j][i-1]!=-10){ //if the plumber can reach this position from the left
                    int temp = dp[j][i-1]; //this is how much the plumber will start moving with
                    for (int k=j;k>=0;k--){
                        if (intMap[k][i]==-10){ //plumber keeps moving until he hits a wall, and break
                            break;
                        }
                        temp += intMap[k][i]; //plumber saves the maximum value of his steps everywhere he goes
                        dp[k][i] = max(dp[k][i],temp);
                    }
                }
            }
        }
        cout<<dp[m-1][n-1]<<endl;
        cin>>m>>n;
    }
    return 0;
}
