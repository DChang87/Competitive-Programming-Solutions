#include<bits/stdc++.h>
using namespace std;
long long  N,X,Q;
long long  countries[3010][2];
long long  dist[3010][3010];
long long  shortest[3010];
long long  sdist[3010];
bool visited[3010];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>countries[i][0]>>countries[i][1];
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dist[i][j]= (countries[i][0]-countries[j][0])*(countries[i][0]-countries[j][0])+ (countries[i][1]-countries[j][1])*(countries[i][1]-countries[j][1]);
        }
    }
    cin>>X;
    X--;
    int cnt=0;
    for (int i=0;i<3010;i++){
        sdist[i]=1e18;
    }
    sdist[X]=0;
    long long newdist;
    long long top;
    while (cnt!=N){
        top = sdist[X];
        visited[X] = true;
        shortest[cnt++] = top;
        for (int i=0;i<N;i++){
            if (i==X || visited[i]) continue;
            newdist = dist[i][X]+top;
            sdist[i] = min(sdist[i],newdist);
        }
        long long minT=1e18;
        for (int i=0;i<N;i++){
            if (!visited[i] && sdist[i]<minT){
                minT = sdist[i];
                X = i;

            }
        }
    }
    sort(shortest,shortest+N);
    cin>>Q;
    long long q;
    for (int i=0;i<Q;i++){
        cin>>q;
        int p = upper_bound(shortest, shortest+cnt, q) - shortest ;
        printf("%d\n",p);

    }
    return 0;
}
