//summing alternate spots
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3010;
int M, N, R, C, X, R1, R2, C1, C2,psum[MAXN][MAXN];

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    do{
        cin >> R >> C >> X;
        psum[R][C] = ((R+C)&1?-X:X); //set alternate values to be negative
    }while (R!=0 || C!=0 || X!=0);
    for (int i=1; i<=M; ++i)
    for (int j=1; j<=N; ++j){
        psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]; //add adjacent (top, left) spots (since they are negative
        //subtract topleft spot (subtracting a negative = adding a positive)
    }
    cin >> R1 >> C1 >> R2 >> C2;
    while (R1!=0 || C1!=0 || R2!=0 || C2!=0){
        int tot = psum[R2][C2] - psum[R2][C1-1] - psum[R1-1][C2] + psum[R1-1][C1-1];
        /*
        X X X X X X X
        X X D X X A X
        X X X x x x X
        X X B x x C X
        */
        //tot = C-A-B+D;
        //small x indicates the desired area
        printf("%d\n",(R1+C1)&1?-tot:tot);
        cin >> R1 >> C1 >> R2 >> C2;
    }
    return 0;
}
