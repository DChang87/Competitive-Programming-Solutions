/*
Suppose that you have n pieces of pie, and k people who are lined up for pieces of pie. All n pieces of pie 
will be given out. Each person will get at least one piece of pie, but mathematicians are a bit greedy at times. 
So, they always get at least as many of pieces of pie as the person in front of them.
For example, if you have 8 pieces of pie and 4 people in line, you could give out pieces of pie in the following 
five ways (with the first person in line being the first number in the list): 
[1, 1, 1, 5], [1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3], [2, 2, 2, 2].
Notice that if k = n, there is only one way to give out the pieces of pie: every person gets exactly one 
piece. Also, if k = 1, there is only one way to give out the pieces of pie: that single person gets all the pieces.
Write a program that determines the number of ways that the pieces of pie can be given out.
Input
The first line of input is the integer number of pieces of pie, n (1 ≤ n ≤ 250).
The second line of input is the integer k which is the number of people in line (1 ≤ k ≤ n).
For at least 20% of the marks for this problem, n ≤ 9. For at least 50% of the marks for this problem, n ≤ 70. 
For at least 85% of the marks for this problem, n ≤ 120.
*/
#include<bits/stdc++.h>
using namespace std;
int N,K; int dp[300][300][300];
int recurse(int n,int k, int MIN){
    if (dp[n][k][MIN]==0){
        if (n==k) dp[n][k][MIN]=1;
        if (k==1) dp[n][k][MIN]=1;
        else{
            int total=0;
            for (int i=MIN;i<(n/k)+1;i++) total += recurse(n-i,k-1,i);
            dp[n][k][MIN]=total;
        }
    }
    return dp[n][k][MIN];
}
int main()
{
    cin>>N>>K;
    cout<<recurse(N,K,1);
}
