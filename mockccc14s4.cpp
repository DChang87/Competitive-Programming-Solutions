#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> grid[40000];
vector<int> path1;
vector<int> path2;
int N,m;
bool visited[40000];
bool DFS1(int index)
{
    visited[index]=true;
    if (index==N-1){
        return true;
    }
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
    if (index==N-1){
        return true;
    }
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
        cin>>a>>b;
        a--;
        b--;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    DFS1(0);
    memset(visited,false,sizeof visited);
    DFS2(0);
    if (path1==path2){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
