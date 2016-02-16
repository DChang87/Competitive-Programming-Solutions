/*
cheesecake works part-time at the Centre for Disease Control and Prevention (CDC), where he researches 
the spread of diseases. An unknown pathogen has just broken out and cheesecake is determined to save the world!
The CDC’s model of the world consists of NN countries numbered 11 through NN, represented by points on a 2-D 
coordinate plane. Country i is located at integral coordinates (xi,yi).
Through extensive research, cheesecake has determined a vital piece of information: the time in 
hours it takes for the pathogen to spread from one country to another is equal to the square of the 
distance between the two countries. For example, if country A is located at (0,0) and country B 
is located at (2,3), it will take 13 hours for country B to be infected after the initial infection 
of country A. The source of the breakout, country X (1≤X≤N), is infected at the 0-th hour.
In order to take preventative measures, cheesecake has been tasked with projecting the rate of infection. 
Specifically, he has to answer Q queries of the following form:
How many countries will be infected after Qi hours?
*/
#include<bits/stdc++.h>
using namespace std;
long long  N,X,Q;
long long  countries[3010][2]; long long  dist[3010][3010]; long long  shortest[3010]; long long  sdist[3010];
bool visited[3010];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){ cin>>countries[i][0]>>countries[i][1];}
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dist[i][j]= (countries[i][0]-countries[j][0])*(countries[i][0]-countries[j][0])+ (countries[i][1]-countries[j][1])*(countries[i][1]-countries[j][1]);
        }
    }
    cin>>X; X--;
    int cnt=0;
    for (int i=0;i<3010;i++){sdist[i]=1e18;}
    sdist[X]=0;
    long long newdist; long long top;
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
