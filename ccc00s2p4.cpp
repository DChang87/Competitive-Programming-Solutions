/*
The date is October 29th, 1969. Today, scientists at UCLA made history by exchanging data 
between two computers over a network. The transmission wasn't very spectacular: 
only the first two letters of the word "login" were received before the system crashed. 
Nevertheless, the researchers are beginning to design larger computer networks and they need your help.
A computer network is a collection of N (2 ≤ N ≤ 100) computers and W wires. 
The computers are identified by the numbers 1, 2, ..., N. Each wire connects exactly two computers, 
allowing packets of data to flow in both directions between the computers. The wires are placed so 
that it is possible to send packets (directly or indirectly by passing through other computers) 
between every pair of computers. In fact, the placement of the wires has been optimized so that there 
is exactly one path between every pair of computers. If the packet travels along several wires to get 
from the source computer to the destination computer, the time needed for the packet to travel along 
this path is the sum of the times required for the packet to travel along each individual wire. 
You are to write a program that computes the amount of time needed for a packet to travel between 
a given pair of distinct computers.
*/
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
        cin>>a>>b>>c; //connections
        connections[a].push_back(make_pair(b,c)); connections[b].push_back(make_pair(a,c));
    }
    for (int i=0;i<P;i++){
        cin>>a>>b; //packages from a to b
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,a));
        int topx,topc;
        bool visited[110];
        memset(visited,false,sizeof visited);
        while (!pq.empty()){
            topc = pq.top().first; topx = pq.top().second; pq.pop();
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
