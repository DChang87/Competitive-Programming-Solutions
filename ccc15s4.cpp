//djikstra with priority_queue sorted by smallest to largest (instead of largest to smallest)
/*
You are travelling on a ship in an archipelago. The ship has a convex hull which is K centimetres thick. 
The archipelago has N islands, numbered from 1 to N. There are M sea routes amongst them, where the i-th 
route runs directly between two different islands ai and bi (1 ≤ ai, bi ≤ N), takes ti minutes to travel 
along in either direction, and has rocks that wear down the ship's hull by hi centimetres. There may be 
multiple routes running between a pair of islands.
You would like to travel from island A to a different island B (1 ≤ A, B ≤ N) along a sequence of sea routes, 
such that your ship's hull remains intact – in other words, such that the sum of the routes' 
hi values is strictly less than K.
Additionally, you are in a hurry, so you would like to minimize the amount of time necessary to reach 
island B from island A. It may not be possible to reach island B from island A, however either due to 
insufficient sea routes or the having the ship's hull wear out.
*/
#include <bits/stdc++.h>
using namespace std;
int K,N,M,A,B;
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
        grid[a].push_back(make_pair(b,make_pair(t,h))); grid[b].push_back(make_pair(a,make_pair(t,h)));
    }
    cin>>A>>B;
    priority_queue<doublep,vector<doublep>,greater<doublep>> pq;
    pq.push(make_pair(0,make_pair(0,A)));
    int pos,time,hull;
    while (!pq.empty()){
        t = pq.top().first; k = pq.top().second.first; b = pq.top().second.second; pq.pop();
        if (k>=K || visited[b][K-k]) continue;
        if (b==B){
            cout<<t<<" "<<k<<endl;
            return 0;
        }
        visited[b][K-k]=true;
        for (int i=0;i<grid[b].size();i++){
            pos = grid[b][i].first; time = grid[b][i].second.first;  hull = grid[b][i].second.second;
            pq.push(make_pair(time+t,make_pair(hull+k,pos)));
        }
    }
    cout<<-1<<endl; return 0;
}
