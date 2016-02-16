/*print the longest path between any two nodes in the tree.*/
#include<bits/stdc++.h>
using namespace std;
int N,a,b;
vector<int> paths[10010];
bool visited[10010];
int MAX=2;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int i=0;i<N-1;i++){
        //describes the paths 
        cin>>a>>b;
        paths[a].push_back(b); paths[b].push_back(a);
    }
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    memset(visited,false, sizeof visited);
    int topc,topx;
    int farthest=1;
    while (!q.empty()){
        topx = q.front().first; topc = q.front().second;q.pop();
        topc+=1;
        if (topc>MAX){
            MAX = topc;
            farthest = topx;
        }
        if (visited[topx])continue;
        visited[topx]=true;
        for (int j=0;j<paths[topx].size();j++){
            if (!visited[paths[topx][j]]){
                q.push(make_pair(paths[topx][j],topc));
            }
        }
    }
    queue<pair<int,int>> q2;
    q2.push(make_pair(farthest,0));
    MAX=0;
    memset(visited,false, sizeof visited);
    while (!q2.empty()){
        topx = q2.front().first;topc = q2.front().second; q2.pop();
        topc+=1;
        MAX = max(MAX,topc);
        if (visited[topx])continue;
        visited[topx]=true;
        for (int j=0;j<paths[topx].size();j++){
            if (!visited[paths[topx][j]]){
                q2.push(make_pair(paths[topx][j],topc));
            }
        }
    }
    cout<<MAX-1<<endl; return 0;
}
