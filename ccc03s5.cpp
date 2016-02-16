/*
You are a salesperson selling trucks which can carry trucks which can carry trucks. Needless to say, 
your trucks are heavy. Also needless to say, you have to drive one of these trucks across a wide wet 
domain, and since it is wet, you need to drive over some bridges. In fact, on every road between two cities, 
there is a bridge but there is not a direct road between every pair of cities.
Each bridge can support a certain maximum weight. This maximum weight is an integer from 0 to 100,000.
You have been given a list of cities where there are customers who are eager to view one of your trucks. 
These cities are called destination cities. Since you must decide which truck you will drive through these 
cities, you will have to answer the following problem: what is the maximum weight that can be driven through 
these destination cities? You are to write a program to solve this problem.
Input
The first line of input will contain three positive integers: c, r and d specifying the number of cities 
(in total), number of roads between cities and number of destination cities, respectively. 
The cities are numbered from 1 to c. There are at most 10,000 cities and at most 100,000 roads.
The next r lines contain triples x y w indicating that this road runs between city x and city y 
and it has a maximum weight capacity of w. The next d lines give the destination cities you must 
visit with your truck. There will be at least one destination city.
You can assume that you are starting in city 1 and that city 1 is not a destination city. 
You can visit the d destination cities in any order, but you must visit all d destination cities.
Output
The output from your program is a single integer, the largest weight that can be driven through all d destination cities.
*/

#include<bits/stdc++.h>
using namespace std;
int C,R,D,x,y,w;
vector<pair<int,int>> roads[100100];
int best[10100];bool visited[10100];int MAX=100010;
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    memset(best,MAX,sizeof best); memset(visited,false,sizeof visited);
    cin>>C>>R>>D;
    for (int i=0;i<R;i++){
        cin>>x>>y>>w;
        roads[x].push_back(make_pair(y,w));roads[y].push_back(make_pair(x,w));
    }
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(MAX,1));
    int topV,topD;
    while (!pq.empty()){
        topD = pq.top().first; topV = pq.top().second; pq.pop();
        if (visited[topV]) continue;
        visited[topV]=true;
        best[topV]=topD;
        for (int i=0;i<roads[topV].size();i++)  pq.push(make_pair(min(roads[topV][i].second,topD),roads[topV][i].first));
    }
    int out=MAX;
    int d;
    for (int i =0;i<D;i++){
        cin>>d;
        out = min(out,best[d]);
    }
    cout<<out<<endl;
}
