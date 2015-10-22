#include <bits/stdc++.h>
using namespace std;
int K,N,M;
int A,B;
bool visited[2010][210];
typedef pair<int,pair<int,int>> doublep;
vector<pair<int,pair<int,int>>> grid[2010];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>K>>N>>M;
    int a,b,t,h,k;
    for (int i=0;i<M;i++){
        cin>>a>>b>>t>>h;
        grid[a].push_back(make_pair(b,make_pair(t,h)));
        grid[b].push_back(make_pair(a,make_pair(t,h)));
    }
    cin>>A>>B;
    priority_queue<doublep,vector<doublep>,greater<doublep>> pq;
    pq.push(make_pair(0,make_pair(0,A)));

    int pos,time,hull;
    while (!pq.empty()){
        t = pq.top().first;
        k = pq.top().second.first;
        b = pq.top().second.second;
        pq.pop();
        if (k>=K || visited[b][K-k]){
            continue;
        }
        if (b==B){
            cout<<t<<" "<<k<<endl;
            return 0;
        }
        visited[b][K-k]=true;
        for (int i=0;i<grid[b].size();i++){
            pos = grid[b][i].first;
            time = grid[b][i].second.first;
            hull = grid[b][i].second.second;
            pq.push(make_pair(time+t,make_pair(hull+k,pos)));
        }
    }
    cout<<-1<<endl;
    return 0;
}
