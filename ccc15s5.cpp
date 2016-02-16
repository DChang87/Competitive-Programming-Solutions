//leo's code, dynamic programming
//take or not take a pie from pile N and pile M
/*
The local pie shop is offering a promotion – all-you-can-eat pies! Obviously, you can't pass up this offer.
The shop lines up N pies from left to right – the i-th pie contains Ai grams of sugar. Additionally, 
another M pies are provided - the i-th of these contains Bi grams of sugar.
You are first allowed to insert each of the M pies from the second group anywhere into the first list of N pies, 
such as its start or end, or in between any two pies already in the list. The result will be a list of N + M pies 
with the constraint that the initial N pies are still in their original relative order.
Following this, you are allowed to take one walk along the new line of pies from left to right, to pick up your 
selection of all-you-can-eat pies! When you arrive at a pie, you may choose to add it to your pile, or skip it. 
However, because you're required to keep moving, if you pick up a certain pie, you will not be able to also pick up 
the pie immediately after it (if any). In other words, you cannot eat consecutive pies in this combined list!
Being a pie connoisseur, your goal is to maximize the total amount of sugar in the pies you pick up from this line. 
How many grams can you get?
Input
The first line of input contains the integer N (1 ≤ N ≤ 3000). The next N lines contain one integer Ai (1 ≤ Ai ≤ 105), 
describing the integer number of grams of sugar in pie i in the group of N pies.
The next line contains the integer M (0 ≤ M ≤ 100), the number of pies in the second list. The next M lines contain one 
integer Bi (1 ≤ Bi ≤ 105), describing the integer number of grams of sugar in pie i in the group of M pies.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, A[3010], B[110], dp[3010][110][110], dp2[3010][110][110];
int greedy2(int i, int j, int k);
int greedy(int i, int j, int k){
    int &ans = dp[i][j][k];
    if (ans!=0) return ans;
    if (i < N){
        ans = max(ans, greedy(i+1,j,k));
        ans = max(ans, A[i+1] + greedy2(i+1,j,k));
    }
    if (j < M){
        ans = max(ans, greedy(i, j+1, k));
        ans = max(ans, B[k+1] + greedy2(i, j+1,k+1));
    }
    return ans;
}
int greedy2(int i, int j, int k){
    int &ans = dp2[i][j][k];
    if (ans!=0) return ans;
    if (i < N) ans = max(ans, greedy(i+1, j, k));
    if (j < M) ans = max(ans, greedy(i, j+1, k));
    return ans;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; ++i) cin >> A[i];
    cin >> M;
    for (int i=1; i<=M; ++i) cin >> B[i];
    sort(B+1, B+1+M);
    reverse(B+1, B+1+M);
    printf("%d",greedy(0,0,0));
    return 0;
}
