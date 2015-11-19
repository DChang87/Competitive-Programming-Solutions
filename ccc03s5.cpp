#include<bits/stdc++.h>
using namespace std;
int C,R,D;
int x,y,w;
vector<pair<int,int>> roads[100100];
int best[10100];
bool visited[10100];
int MAX=100010;
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    memset(best,MAX,sizeof best);
    memset(visited,false,sizeof visited);
    cin>>C>>R>>D;
    for (int i=0;i<R;i++){
        cin>>x>>y>>w;
        roads[x].push_back(make_pair(y,w));
        roads[y].push_back(make_pair(x,w));
    }
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(MAX,1));
    int topV,topD;
    while (!pq.empty()){
        topD = pq.top().first;
        topV = pq.top().second;
        pq.pop();
        if (visited[topV]){
            continue;
        }
        visited[topV]=true;

        best[topV]=topD;
        for (int i=0;i<roads[topV].size();i++){
            pq.push(make_pair(min(roads[topV][i].second,topD),roads[topV][i].first));
        }
    }
    int out=MAX;
    int d;
    for (int i =0;i<D;i++){
        cin>>d;
        out = min(out,best[d]);
    }
    cout<<out<<endl;
}
