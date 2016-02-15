#include<bits/stdc++.h>
using namespace std;
int N,a,b;
int gcd(int a,int b){
    while (b>0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int lcm(int a,int b){
    return a * (b/gcd(a,b));
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    while (N!=0){
        int path[N];
        for (int i=0;i<N;i++){
            cin>>a>>b;
            a--;b--;
            path[a]=b;
        }
        bool visited[N];
        vector<int> len;
        memset(visited,false,sizeof visited);
        for (int i=0;i<N;i++){
            if (visited[i])continue;
            visited[i]=true;
            int cur=i;
            int counter=1;
            while (true){
                cur = path[cur];
                visited[cur] = true;
                if (cur==i){
                    len.push_back(counter);
                    break;
                }
                counter++;
            }
        }
        int num=1;
        for (int i=0;i<len.size();i++){
            num = lcm(num,len[i]);
        }
        cout<<num<<endl;
        cin>>N;
    }
    return 0;
}
