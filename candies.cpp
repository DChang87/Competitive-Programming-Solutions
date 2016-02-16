/*
Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  
All the children sit in a line ( their positions are fixed), and each  of them has a rating score according 
to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children 
sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, 
so she needs to minimize the total number of candies given to the children.
Input Format
The first line of the input is an integer N, the number of children in Alice's class. Each of the following N 
lines contains an integer that indicates the rating of each child.
*/
#include<bits/stdc++.h>
using namespace std;
int N; int rating[100010]; int dp[100010]; int incr[100010];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++) cin>>rating[i];
    for (int i=0;i<N;i++) dp[i]=1;
    incr[N-1]=1;
    for (int i=N-2;i>=0;i--){
        if (rating[i]>rating[i+1])    incr[i] = incr[i+1]+1;
        else{           incr[i]=1;}
    }
    for (int i=1;i<N;i++){
        if (rating[i]>rating[i-1] && incr[i]<=incr[i-1]){ //new increment
            int ori_count=incr[i];
            incr[i]=incr[i-1]+1;
        }
    }
    int sum=0;
    for (int i=0;i<N;i++)    sum += incr[i];
    cout<<sum<<endl;
    return 0;
}
