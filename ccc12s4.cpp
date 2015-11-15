//BFS, hashing
#include<bits/stdc++.h>
using namespace std;
set<int> visited;
int N, n, targetCode,hashCode,ans;


int pow(int base, int exp)
{
	int x = 1;
	for (int i = 0; i < exp; i++) x *=base;
	return x;
}

int bfs(int hashCode)
{
    queue<pair<int,int>> q; //pair<hashCode,numMoves>
    q.push(make_pair(hashCode,0));
    while (!q.empty()){
        hashCode = q.front().first;
        int moves = q.front().second;
        q.pop();
        if (hashCode==targetCode){
            return moves;
        }
        if (!visited.insert(hashCode).second){ //if visited
            continue;
        }
        int stacks[9];
        for (int i=0;i<9;i++){
            stacks[i]=0x7fffffff;
        }
        int newHash = hashCode;
        for (int i=N;i>0;i--){
            //find the position of the coin
            //check against the position in the stack array
            int pos = newHash/pow(8,i);
            stacks[pos] = min(stacks[pos],i);
            newHash%= pow(8,i);
        }
        for (int i=1;i<=N;i++){
            //go through each position
            if (i>1){
                if (stacks[i]<stacks[i-1]){
                    q.push(make_pair(hashCode-pow(8,stacks[i]),moves+1));
                }
            }
            if (i<N){
                if (stacks[i]<stacks[i+1]){
                    q.push(make_pair(hashCode+pow(8,stacks[i]),moves+1));
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    cin>>N;
    while (N!=0){
        visited.clear();
        hashCode = 0;
        targetCode = 0;
        for (int i=0;i<N;i++){
            cin>>n;
            hashCode += (i+1)*pow(8,n);//i+1 multipled by the nth power of 8
        }
        for (int i=0;i<=N;i++){
            targetCode += i*pow(8,i);
        }
        ans = bfs(hashCode);
        if (ans>=0){
            cout<<ans<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
        cin>>N;
    }
    return 0;
}
