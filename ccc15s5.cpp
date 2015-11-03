//leo's code, dynamic programming
//take or not take a pie from pile N and pile M

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
    if (i < N){
        ans = max(ans, greedy(i+1, j, k));
    }
    if (j < M){
        ans = max(ans, greedy(i, j+1, k));
    }
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
