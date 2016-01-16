#include<bits/stdc++.h>
using namespace std;
int n,hill;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    stack<pair<long long, long long>> hills;
    long long counter=0;
    for (int i=0;i<n;i++){
        cin>>hill;
        pair<long long, long long> p(hill,0);
        while (!hills.empty()){
            if (hills.top().first<p.first){
                counter+=hills.top().second;
                hills.pop();
            }
            else if (hills.top().first==p.first){
                p.second = hills.top().second;
                counter+=p.second;
                hills.pop();
            }
            else{
                counter++;
                break;
            }
        }
        p.second++;
        hills.push(p);
    }
    cout<<counter<<endl;
    return 0;
}

