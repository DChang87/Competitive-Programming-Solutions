#include <bits/stdc++.h>

using namespace std;

int psum[100010];
set<int> occur[2010];

int main()
{
    //freopen("DMOPC.txt","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    int N, K, Q;
    cin >> N >> K >> Q;
    for (int i=1; i<=N; ++i){
        cin >> psum[i];
        occur[psum[i]+1000].insert(i);
        psum[i]+=psum[i-1];
    }
    while (Q--){
        int x, y, a, b, tot = 0;
        cin >> a >> b >> x >> y;
        tot = psum[y] - psum[x-1];
        auto it = occur[a+1000].lower_bound(x), it2 = occur[b+1000].lower_bound(x);
        if (it == occur[a+1000].end() || y < *it || it2 == occur[b+1000].end() || y < *it2){
            cout << "No" << '\n';
        }
        else if (tot >  K){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
    return 0;
}
