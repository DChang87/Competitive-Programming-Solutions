/*
DP: exchange tiles
there's no limit on the size of tiles that farmer can ask for
*/
#include <stdio.h>
#define MAX_M 10000
#define MAX_N 10
#define INF 1000000000
int best[MAX_M+1][MAX_N+1]; 
//best[i][j] denote the minimum cost of building a total area of i by exchanging only tiles 1 through j
int A[MAX_M+1];
int main(void)
{
  int M, N, i, j, k;
  freopen ("tilechng.in", "r", stdin);
  freopen ("tilechng.out", "w", stdout);
  scanf ("%d %d", &N, &M);//number of tiles, size of area looking to achieve
  for (i=1; i<=N; i++)
    scanf ("%d", &A[i]); //tiles i purchased to be exchanged on my side
  for (i=1; i<=M; i++)    best[i][0] = INF;
  for (j=1; j<=N; j++) //GO THROUGH ALL THE TILES
    for (i=0; i<=M; i++) { //go through all total areas
        best[i][j] = INF;
        for (k=1; k*k<=i; k++) //go through all possible tiles to use (tiles will be smaller than the total area)
        if ((A[j]-k)*(A[j]-k) + best[i-k*k][j-1] < best[i][j]) best[i][j] = (A[j]-k)*(A[j]-k) + best[i-k*k][j-1];
    }
  if (best[M][N]==INF)  printf ("-1\n");
  else    printf ("%d\n", best[M][N]);
  return 0;
}
