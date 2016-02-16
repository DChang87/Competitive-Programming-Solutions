/*
At the Canadian Carnival Competition (CCC), a popular game is Bowling for Numbers. A large number of bowling pins are 
lined up in a row. Each bowling pin has a number printed on it, which is the score obtained from knocking over that pin. 
The player is given a number of bowling balls; each bowling ball is wide enough to knock over a few consecutive and adjacent pins.
For example, one possible sequence of pins is: 2 8 5 1 9 6 9 3 2
If Alice was given two balls, each able to knock over three adjacent pins, the maximum score Alice could achieve 
would be 39, the sum of two throws: 2 + 8 + 5 = 15, and 9 + 6 + 9 = 24.
Bob has a strategy where he picks the shot that gives him the most score, then repeatedly picks the shot that 
gives him the most score from the remaining pins. This strategy doesn’t always yield the maximum score, but it 
is close. On the test data, such a strategy would get a score of 20%.
Input
Input consists of a series of test cases. The first line of input is t, 1 ≤ t ≤ 10, indicating the number of 
test cases in the file. The first line of each test case contains three integers n k w. First is the integer n, 
1 ≤ n ≤ 30000, indicating the number of bowling pins. The second integer, k, 1 ≤ k ≤ 500, giving the number of 
bowling balls available to each player. The third and final integer is w, 1 ≤ w ≤ n, the width of the bowling 
ball (the number of adjacent pins it can knock over). The next n lines of each test case each contain a single 
non-negative integer less than 10000, giving the score of the pins, in order. 20% of the test data will have size n ≤ 50.
*/
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for (int i=0;i<N;i++){
        int n,k,w;
        cin>>n>>k>>w;
        int balls[n]; int sum[n]; int temps=0;
        for (int j=0;j<n;j++){
            cin>>balls[j];
            sum[i]=0;
        }
        for (int j=0;j<w;j++) temps+=balls[j];
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
        for (int j=1;j<n;j++) dp[0][j]=0;
        for (int j=1;j<=k;j++){
            for (int m=1;m<n;m++){
                dp[j][m]=-1;
            }
        }
        for (int j=1;j<=k;j++){
            for (int m=n-1;m>=0;m--){
                if (m>=n-w) dp[j][m]=sum[m];
                else{ dp[j][m] = max(sum[m]+dp[j-1][m+w],dp[j][m+1]);}
            }
        }
        cout<<dp[k][0]<<endl;;
    }
}
