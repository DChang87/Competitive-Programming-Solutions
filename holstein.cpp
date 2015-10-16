/*
ID: jezhao11
LANG: C++11
TASK: holstein
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int vit[25], curr[25];
	for (int i = 0; i < n; ++i)
		cin >> vit[i];
	int g; cin >> g;
	static int feed[15][25];
	for (int i = 0; i < g; ++i)
		for (int j = 0; j < n; ++j)
			cin >> feed[i][j];
	int ans = 0x7fffffff;
	for (int i = 1; i <= (1<<g); ++i){
		fill_n(curr, 25, 0);
		for (int j = 0; j < g; ++j)
			if ((i & 1<<j) != 0)
				for (int k = 0; k < n; ++k)
					curr[k] += feed[j][k];
		bool ok = true;
		for (int k = 0; k < n; ++k)
			if (curr[k] < vit[k])
				ok = false;
		if (ok && __builtin_popcount(i) < __builtin_popcount(ans))
			ans = i;
	}
	cout << __builtin_popcount(ans);
	for (int i = 0; i < g; ++i)
		if ((ans & 1<<i) != 0)
			cout << ' ' << i+1;
	cout << '\n';
return 0;}
