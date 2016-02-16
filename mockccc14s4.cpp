/*
Alice heard that her secret love interest, Bob, is going on a roadtrip to visit his friend in another city. 
She decides to follow him along the way to see if the friend is actually romantically affiliated with Bob 
(in which case, the outcome is not going to be pretty). Alice does not know the route that Bob is going to take, 
so she has acquired a map of the country. In their country, there are N (1 ≤ N ≤ 40 000) cities conveniently 
labeled from 1 to N, and M (1 ≤ M ≤ 200 000) bidirectional roads that run between the cities. 
There is at most one road between any pair of cities.

Both of them are currently in city 1, and Bob would like to go to city N. 
Alice also wants to get to city N eventually, but how she gets there does not matter. 
Bob's route will never return to the same city twice, and Alice does not plan to waste time by 
returning to the same city in her route either. The problem is, Alice cannot take the exact same route as 
Bob because Bob might get suspicious of a car that's following him for the entire trip. At some point, 
Alice will have to split up with Bob for a while. Alice needs to know whether there are at least two distinct 
ways to get from city 1 to city N.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> grid[40000]; vector<int> path1; vector<int> path2;
int N,m;
bool visited[40000];
bool DFS1(int index)
{
    visited[index]=true;
    if (index==N-1)        return true;
    for (int i=0;i<grid[index].size();i++){
        if (!visited[grid[index][i]]){
            if (DFS1(grid[index][i])){
                path1.push_back(grid[index][i]);
                return true;
            }
        }
    }
    return false;
}
bool DFS2(int index)
{
    visited[index]=true;
    if (index==N-1)        return true;
    for (int i=grid[index].size()-1;i>=0;i--){
        if (!visited[grid[index][i]]){
            if (DFS2(grid[index][i])){
                path2.push_back(grid[index][i]);
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>N>>m;
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b; a--; b--;
        grid[a].push_back(b); grid[b].push_back(a);
    }
    DFS1(0);
    memset(visited,false,sizeof visited);
    DFS2(0);
    if (path1==path2)       cout<<"No"<<endl;
    else{        cout<<"Yes"<<endl;    }
    return 0;
}
