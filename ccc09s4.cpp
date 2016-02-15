#include<bits/stdc++.h>
using namespace std;
int N,T,x,y,c,K,z,p,D;
vector<pair<int,int>> routes[5010];
bool visited[5010];
int pencils[5010][2];
int top[5010];
typedef pair<int,int> pi;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    cin>>T;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0;i<T;i++){
        cin>>x>>y>>c;
        routes[x].push_back(make_pair(y,c));
        routes[y].push_back(make_pair(x,c));
    }
    cin>>K;
    int MIN=1000000;
    for (int i=0;i<K;i++){
        cin>>z>>p;
        pq.push(make_pair(p,z));
    }
    cin>>D;
    int topt,topc;
    memset(visited,false, sizeof visited);
    while (!pq.empty()){
        topt = pq.top().second;
        topc = pq.top().first;
        pq.pop();
        if (topt==D){
            cout<<topc<<endl;
            break;
        }
        if (visited[topt]) continue;
        visited[topt] = true;
        for (int j=0;j<routes[topt].size();j++){
            if (!visited[routes[topt][j].first]){
                pq.push(make_pair(routes[topt][j].second+topc,routes[topt][j].first));
            }
        }
    }

    return 0;
}

