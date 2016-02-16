//summing alternate spots
/*
You are given a checkerboard with M rows and N columns (1 ≤ M,N ≤ 3000). Up to 100000 of these cells have specified values 
written in them, and the rest are zeroes. For top-secret strategic reasons which are given out on a need-to-know basis only 
(and you do not, at the present moment, need to know) you must write a program that will answer up to 100000 queries of the form:
Given the coordinates of two squares on the checkerboard, find the alternating sum of all of the numbers within the rectangle 
delimited by those two squares. By alternating sum what is meant is that we add all numbers in squares with the same colour as 
the first square given, and subtract all numbers with the opposite colour.
Input
The first line of the input file contains the integers M and N.
A number of input lines then follow. Each line contains three space-separated integers R, C, and X (1 ≤ R ≤ M, 1 ≤ C ≤ N, 
-1000 ≤ X ≤ 1000), indicating that the value X is written in row R and column C. No cell will be given twice in the input. 
The last line is followed by a line containing three zeroes, signifying the end of this section of input.
Following this are a number of lines containing queries. Each line contains four space-separated integers: R1, C1, R2, and C2 
(1 ≤ R1 ≤ R2 ≤ M, 1 ≤ C1 ≤ C2 ≤ N). Output the alternating sum of all squares contained within the box [R1,R2] × [C1,C2], as described.
*/
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
