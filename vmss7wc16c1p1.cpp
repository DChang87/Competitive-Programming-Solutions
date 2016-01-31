#include<bits/stdc++.h>
using namespace std;
int N;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    int root = sqrt(N)+1;

    bool prime[root+10];
    bool visited[root+10];

    memset(prime,false,sizeof prime);
    memset(visited, false, sizeof visited);
    for (int i=2;i<=root;i++){
        if (visited[i]) continue;
        int n = i;
        prime [i]=true;
        while (n<=root){
            visited[n]=true;
            n+=i;
        }
    }

    int counter=2;
    bool out = false;
    while(counter<=root){
        if (prime[counter]){
            if (N%counter==0){
                N/=counter;
                out=true;
                cout<<counter<<endl;
            }
            else{
                counter++;
            }
        }
        else{
            counter++;
        }
    }
    if (N!=1){
        cout<<N<<endl;
    }

    return 0;
}

