#include<bits/stdc++.h>
using namespace std;
int N,W,P;
vector<pair<int,int>> connections[110];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N>>W>>P;
    int a,b,c;
    for (int i=0;i<W;i++){
        cin>>a>>b>>c;
        connections[a].push_back(make_pair(b,c));
        connections[b].push_back(make_pair(a,c));
    }
    for (int i=0;i<P;i++){
        cin>>a>>b;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,a));
        int topx,topc;
        bool visited[110];
        memset(visited,false,sizeof visited);
        while (!pq.empty()){
            topc = pq.top().first;
            topx = pq.top().second;
            pq.pop();
            if (topx == b){
                cout<<topc<<endl;
                break;
            }
            if (visited[topx])continue;
            visited[topx]=true;
            for (int k=0;k<connections[topx].size();k++){
                if (!visited[connections[topx][k].first]){
                    pq.push(make_pair(topc + connections[topx][k].second,connections[topx][k].first));
                }
            }
        }
    }
    return 0;
}

