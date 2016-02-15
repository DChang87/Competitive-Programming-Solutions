#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
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
    cout << dp[B][T];
	return 0;
}
