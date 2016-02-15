#include<bits/stdc++.h>
using namespace std;
int N,M;
int Xs[100100],Ys[100100];
int lastPos;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int u=0;u<N;u++){
        cin>>M;
        for (int j=0;j<M;j++){
            cin>>Xs[j];
        }
        for (int j=0;j<M;j++){
            cin>>Ys[j];
        }
        int maxDist=0;
        lastPos=0;
        for (int i=0;i<M;i++){
            for (int j=lastPos;j<M;j++){
                if (Ys[j]>=Xs[i]){
                    maxDist=max(maxDist,j-i);
                    lastPos=j;
                }
                else{break;}
            }
        }
        /* OR THIS CODE
        int counter=0;

        for (int i=0;i<=n;i++){
            while (Y[counter]>=X[i] && counter<n){
                counter++;
            }

            maxD = max(maxD,counter-i-1);
        }
        */
        cout<<"The maximum distance is "<<maxDist<<endl;
    }

    return 0;
}


