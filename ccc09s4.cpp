/*
In Doubleclickland, there are N cities (N ≤ 5,000), with each city having various trade routes to other cities. 
In total, there are T trade routes (0 ≤ T ≤ 25,000,000). in Doubleclickland. For each trade route between two 
cities x and y, there is a transportation cost C(x; y) to ship between the cities, where C(x, y) > 0, 
C(x, y) ≤ 10,000 and C(x, y) = C(y, x). Out of the N cities, K (1 ≤ K ≤ N) of these cities have stores with 
really nice pencils that can be purchased on-line. The price for each pencil in city x is Px (0 ≤ Px ≤ 10,000).
Find the minimal price to purchase one pencil on-line and have it shipped to a particular city D (1 ≤ D ≤ N) 
using the cheapest possible trade-route sequence. Notice that it is possible to purchase the pencil in city D 
and thus require no shipping charges.
Input
The first line of input contains N, the number of cities. You can assume the cities are numbered from 1 to N. 
The second line of input contains T, the number of trade routes. The next T lines each contain 3 integers, 
x, y, C(x, y), to denote the cost of using the trade route between cities x and y is C(x, y). 
The next line contains the integer K, the number of cities with a store that sells really nice pencils on-line. 
The next K lines contains two integers, z and Pz, to denote that the cost of a pencil in city z is Pz. 
The last line contains the integer D, the destination city.
Output
Output the minimal total cost of purchasing a pencil on-line and shipping it to city D.
*/
#include<bits/stdc++.h>
using namespace std;
int N,T,x,y,c,K,z,p,D;
vector<pair<int,int>> routes[5010];
bool visited[5010]; int pencils[5010][2]; int top[5010];
typedef pair<int,int> pi;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N>>T;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0;i<T;i++){
        cin>>x>>y>>c;
        routes[x].push_back(make_pair(y,c));routes[y].push_back(make_pair(x,c));
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
        topt = pq.top().second; topc = pq.top().first; pq.pop();
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
