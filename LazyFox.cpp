//Leo's code
//nice DP solution
#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PIPII pair<int,pair<int,int>>
#define MAXN 2010

PII points[MAXN];
vector<PIPII> dp;
int dist[MAXN],candy[MAXN],pcandy[MAXN],N,d,a,b;

int calc(int i,int j){
    int distx,disty;
    distx = points[i].first-points[j].first;
    disty = points[i].second-points[j].second;
    return distx*distx + disty*disty;
}
int main()
{
	int N;
	cin >> N;
	points[0].first=0;
    points[0].second=0;
	for (int i = 1; i <= N; ++i)
		cin >> points[i].first>>points[i].second;

	for (int i=0;i<=N;i++){
        for (int j=i+1;j<=N;j++){
            dp.pb(mp(calc(i,j),mp(i,j)));
        }
	}
	sort(dp.begin(),dp.end());

	for (int i=0;i<dp.size();i++){
        d = dp[i].first; a = dp[i].second.first; b = dp[i].second.second;
        if (d!=dist[a]){
            pcandy[a]=candy[a];
            dist[a]=d;
        }
        if (d!=dist[b]){
            pcandy[b]=candy[b];
            dist[b]=d;
        }
        candy[a] = max(candy[a],pcandy[b]+1);
        if (a!=0){
            candy[b] = max(candy[b],pcandy[a]+1);
        }
	}
	cout<<candy[0]<<endl;
	return 0;
}
