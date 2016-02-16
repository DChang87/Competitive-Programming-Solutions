/*
After considering to buy a brand new Atari or Commodore computer (based on your extensive research in late February), 
you decide to get the best value for your dollar by building your own.
The computer that you are going to build is composed of T (1 ≤ T ≤ 5) different types of components. Your computer 
must have exactly one of each type of component.
Each component has an integer cost ci (1 ≤ ci ≤ 3000), an integer value vi (1 ≤ vi ≤ 3000), and type ti (1 ≤ ti ≤ T).
Your on-line computer parts store has N different components (1 ≤ N ≤ 1000) that you can select from.
For a given budget B (1 ≤ B ≤ 3000), maximize the total value of the components in your computer.
If you cannot construct such a computer, you should print -1.
Input
The first line contains T, the number of types of components your computer requires. The next line contains the number N, 
followed by N lines of three integers, representing ci, vi, and ti, each separated by one space. The last line of input is 
the budget B.
Output
Output the value of the maximum valued computer you can create which costs at most B, or -1 if you cannot construct a computer.
*/
#include<bits/stdc++.h>
using namespace std;
int T,N,B,c,v,t,dp[3005][6];
vector<pair<int, int>> types[6];
int main()
{
    scanf("%d%d", &T, &N);
    for (int i = 0; i != N; ++i)
	{
		scanf("%d%d%d", &c, &v, &t);
		types[t].push_back(make_pair(c, v));
	}
	scanf("%d",&B);
    for (int type=1;type<=T;type++){
        for (int comp=0;comp<types[type].size();comp++){
            for (int budget = 1;budget<=B;budget++){
                if (budget >= types[type][comp].first){
                    dp[budget][type] = max(dp[budget][type],dp[budget - types[type][comp].first][type-1] + types[type][comp].second);
                }
            }
        }
    }
    cout << dp[B][T]; return 0;
}
