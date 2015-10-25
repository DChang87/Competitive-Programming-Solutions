//Solution Notes: This problem is solved by dynamic programming. Let good[n][B_2][B_3] be "true" if one can reach a state using only bales 1..n in which B_2 and B_3 denote the total amount of hay in barns 2 and 3 (just as in the problem statement). Note that we don't need to include B_1 in our state space, since B_1 is determined by knowing n, B_2, and B_3: B_1 is the total size of bales 1..n minus B_2 minus B_3. We now fill in the table of all good[][][] values, and the solution is obtained by looking at good[N][][] for the "true" entry with the smallest value of max(B_1,B_2,B_3). To make the algorithm as memory-efficient as possible, we note that we only need to store two "levels" of the table (for n and n-1) at a time. Furthermore, we know that the optimal solution is at most the sum of all bale sizes divided by 3, so we can upper bound the optimal solution by at most 700, limiting the maximum necessary size of dimensions 2 and 3 in our state space to 700 and speeding up the running time considerably.
//beast DP solution, different use of DP

#include <iostream>
#include <fstream>

using namespace std;
const int MAXS = 700;

ifstream fin ("baleshare.in");
ofstream fout ("baleshare.out");

int n, bale, tsum;
bool good[2][MAXS+100][MAXS+100];

int main()
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < MAXS; j++)
            for (int k = 0; k < MAXS; k++)
                good[i][j][k] = false;
    good[0][0][0] = true;
    tsum = 0;
    
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> bale;
        tsum += bale;
        for (int j = 0; j < MAXS; j++)
            for (int k = 0; k < MAXS; k++)
            {
                if (good[i%2][j][k])
                {
                    good[(i+1)%2][j][k] = true;
                    good[(i+1)%2][j+bale][k] = true;
                    good[(i+1)%2][j][k+bale] = true;
                }
            }
    }
    
    int ans = MAXS;
    for (int i = 0; i < MAXS; i++)
        for (int j = 0; j < MAXS; j++)
            if (good[n%2][i][j])
                ans = min (ans, max (i, max (j, tsum - (i + j))));
    fout << ans << "\n";
    return 0;
}
