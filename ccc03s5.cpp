//this code gets SIGSEGV but the idea behind it is right
//prim's, greedy algorithm, graph theory

#include<bits/stdc++.h>
using namespace std;
int bridges[10100][10100];
int maxWeights[10100];
bool visited[10100];
int c,r,d;
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    cin>>c>>r>>d;
    for (int i=0;i<c;i++){
        for (int j=0;j<c;j++){
            bridges[i][j]=-1;
        }
    }
    int x,y,w;
    for (int i=0;i<r;i++){
        cin>>x>>y>>w;
        x--;
        y--;
        bridges[x][y] = max(bridges[x][y],w);
        bridges[y][x] = max(bridges[y][x],w);
    }
    for (int i=0;i<c;i++){
        maxWeights[i]=0;
        visited[i]=false;
    }
    maxWeights[0]=100000;
    int maxt=0, maxv=0;
    int currentT;
    while (true){
        if (maxt==-1){ //if there are no more towns to visit
            break;
        }
        currentT = maxt; //the town that the program is currently at
        maxv=0; //maximum weight of the next town to travel to (maxt)
        maxt=-1; //next town that has the maximum weight to travel to
        visited[currentT]=true;
        for (int i=0;i<c;i++){ //go through every town
            maxWeights[i] = max(maxWeights[i],min(maxWeights[currentT],bridges[currentT][i]));
            //if there is a heavier weight way to travel to town i, replace the current limit
            if (maxWeights[i]>maxv && !visited[i]){
                //if this town has higher maximum weight than currently recorded maximum weight (maxv) and it has not been visited
                maxv=maxWeights[i];
                maxt= i;
            }
        }
    }
    int minOut=100000;
    int town;
    for (int i=0;i<d;i++){
        cin>>town;
        town--;
        //take the minimum out of all weights for the towns that must be visited
        minOut = min(minOut,maxWeights[town]);
    }
    cout<<minOut<<endl;
}
