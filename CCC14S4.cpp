//line sweep
/*
You are laying N rectangular pieces of grey-tinted glass to make a stained glass window. Each piece of glass adds an integer 
value "tint-factor". Where two pieces of glass overlap, the tint-factor is the sum of their tint-factors.
You know the desired position for each piece of glass and these pieces of glass are placed such that the sides of each 
rectangle are parallel to either the x-axis or the y-axis (that is, there are no "diagonal" pieces of glass).
You would like to know the total area of the finished stained glass window with a tint-factor of at least T.
Input
The first line of input is the integer N (1 ≤ N ≤ 1000), the number of pieces of glass. The second line of input is the 
integer T (1 ≤ T ≤ 1 000 000 000), the threshold for the tint-factor. Each of the next N lines contain five integers, 
representing the position of the top-left and bottom-right corners of the i-th piece of tinted glass followed by the 
tint-factor of that piece of glass. Specifically, the integers are placed in the order xl yt xr yb ti, where the top-left 
corner is at (xl, yt) and the bottom-right corner is at (xr, yb), and tint-factor is ti. You can assume that 1 ≤ ti ≤ 1 000 000. 
The top-most, left-most co-ordinate where glass can be placed is (0, 0) and you may assume 0 ≤ xl < xr ≤ K and 0 < yt < yb ≤ K
*/
#include<bits/stdc++.h>
using namespace std;
int N,K;
const int MAX = 1010;
map<long long, long long> Xv2i, Yv2i, Xi2v, Yi2v; //val to index, index to val
int X1[MAX],Y1[MAX],X2[MAX],Y2[MAX],T[MAX];
long long tint[MAX*2][MAX*2];
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    set<int> Xs,Ys;
    for (int i=0;i<N;i++)
    {
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i]>>T[i];
        Xs.insert(X1[i]);
        Xs.insert(X2[i]);
        Ys.insert(Y1[i]);
        Ys.insert(Y2[i]);
    }
    int xcount=1,ycount=1;
    for (int i:Xs)
    {
        Xi2v[xcount] = i;
        Xv2i[i]=xcount++;
    }
    for (int i:Ys)
    {
        Yi2v[ycount] = i;
        Yv2i[i]=ycount++;
    }
    for (int i=0;i<N;i++){
        for (int j=Yv2i[Y1[i]];j<Yv2i[Y2[i]];j++)
        {
            tint[j][Xv2i[X1[i]]]+=T[i];
            tint[j][Xv2i[X2[i]]]-=T[i];
        }
    }
    for (int i=1;i<ycount;i++){
        for(int j=1;j<xcount;j++)
        {
            tint[i][j]+=tint[i][j-1];
        }
    }
    long long tot=0;
    for (int i=1;i<ycount;i++){
        for (int j=1;j<xcount;j++){
            if (tint[i][j]>=K)
            {
                tot+= (Yi2v[i+1]-Yi2v[i])*(Xi2v[j+1]-Xi2v[j]);
            }
        }
    }
    cout<<tot<<endl;
    return 0;
}
