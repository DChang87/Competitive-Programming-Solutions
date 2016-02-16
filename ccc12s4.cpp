//BFS, hashing
/*
When she is bored, Jo Coder likes to play the following game with coins on a table. She takes a set of distinct coins and 
lines them up in a row. For example, let us say that she has a penny (P, worth $0.01), a nickel (N, worth $0.05), and a dime 
(D, worth $0.10). She lines them up in an arbitrary order (for example, D N P), and then moves them around with the goal of 
placing them in strictly increasing order by value, that is P N D (i.e., $0.01, $0.05, $0.10). She has particular rules that she follows:
The initial coin line-up defines all positions where coins can be placed. That is, no additional positions can be added later, 
and even if one of the positions does not have a coin on it at some point, the position still exists.
The game consists of a sequence of moves and in each move Jo moves a coin from one position to an adjacent position.
The coins can be stacked, and in a move Jo always takes the top coin from one stack and moves it to the top of another stack.
In a stack of coins, Jo never places a higher-value coin on top of a lower-value coin.
For simplicity, let the coins have consecutive integer values (e.g., denote the penny as 1, nickel as 2, and dime as 3). 
May be impossible
*/
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
        if (ans>=0) cout<<ans<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
        cin>>N;
    }
    return 0;
}
