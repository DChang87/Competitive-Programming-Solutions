//upper and lower bounds with vectors
//Royal Guard
//Guard walks around, check how many buildings the guard will walk into
#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<pair<int,int>> Xs,Ys;
int x,y,xf,yf;
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>x>>y; //storing all of the building positions
        Xs.push_back(make_pair(x,y));
        Ys.push_back(make_pair(y,x));
    }
    sort(Xs.begin(),Xs.end());
    sort(Ys.begin(),Ys.end());
    cin>>M; //number of steps
    cin>>x>>y;
    long long int tot=0;
    for (int i=0;i<M-1;i++){
        //paths of the guard
        cin>>xf>>yf;
        if (x==xf){
            //horizontal travel
            tot += upper_bound(Xs.begin(),Xs.end(),make_pair(x,max(y,yf)))-lower_bound(Xs.begin(),Xs.end(),make_pair(x,min(y,yf)));
        }
        else{
            tot+= upper_bound(Ys.begin(),Ys.end(),make_pair(y,max(x,xf)))-lower_bound(Ys.begin(),Ys.end(),make_pair(y,min(x,xf)));
        }
        x = xf;
        y = yf;
    }
    cout<<tot<<endl;

}
