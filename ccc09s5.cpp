#include<bits/stdc++.h>
using namespace std;

int X,Y,K;
int MAX=0;
int diff[30010][1010];
int main()
{
    cin>>X>>Y>>K;
    int x,y,r,b;
    for (int i=0;i<K;i++){
        cin>>y>>x>>r>>b;
        x--;y--;
        int left,right;
        for (int j=max(0,y-r);j<=min(y+r,Y-1);j++){
            int xroot = pow(r*r-(j-y)*(j-y),0.5);
            left = max(0,x-xroot);
            right = min(x+xroot,X-1);
            diff[left][j]+=b;
            diff[right+1][j]-=b;
        }
    }

    int counter=0;
    for (int i=0;i<X;i++){
        for (int j=0;j<Y;j++){
            if (i!=0){
                diff[i][j]+=diff[i-1][j];
            }
            if (diff[i][j]==MAX){
                counter++;
            }
            if (diff[i][j]>MAX){
                MAX = diff[i][j];
                counter=1;
            }
        }
    }
    cout<<MAX<<endl;
    cout<<counter<<endl;
}
