/*
N restaurants in his distribution chain, which are arranged along a highway at distinct positions.
Each restaurant has a position on the highway, pi, which represents its distance from position 0 and a value fi (fi ∈{0,1}). 
If fi =1, the restaurant is said to be fringy. Otherwise it is regular. In addition to the N restaurants, 
Gus has a math lab at position 0 on the highway.
Gus wants to send a truck from his math lab at position 0 to the last restaurant in his distribution chain. 
The truck has a fuel capacity F and can only travel a distance of F before it must stop at a restaurant and 
refuel (assume the truck starts with a full tank of fuel at the beginning). The driver also has the choice to 
simply drive by a restaurant. However, the truck must stop at all fringy restaurants so the driver can do math. 
Fring also wants the truck to stop at at most KK restaurants (including the last restaurant, but not including the 
math lab) in order to increase the efficiency of his distribution network.
Help Fring calculate the minimum fuel capacity the truck needs so that it will be able to reach the last restaurant 
while stopping at most K times.
*/
#include<iostream>
using namespace std;
long long n,kval;
bool checkValid(long long p[],long long f[],int fuel, int k)
{
    int lastfueld=0;
    for (int i=1;i<=n;i++){
        if (p[i]-p[i-1]>fuel){
            return false;
        }
    }
    for (int pos=1;pos<n;pos++){
        if (f[pos]==1){
            k--;
            lastfueld=pos;
        }
        else if (p[pos+1]-p[lastfueld]>fuel){
            lastfueld=pos;
            k--;
        }
    }
    k--;
    if (k<0)return false;
    return true;
}
int main()
{
    cin>>n>>kval;
    long long p[n+1],f[n+1], P,F;
    long long fringes=0;
    p[0]=0; f[0]=0;
    bool fringy=false;
    for (long long i=0;i<n;i++){
        cin>>P>>F;
        if (F==1 || i==n-1){ fringes++;}
        p[i+1]=P;  f[i+1]=F;
        if (fringes>kval) fringy=true;
    }
    if (fringy){
        cout<<"DEA Bust!"<<endl;
        return 0;
    }
    int minbound=0,maxbound=p[n]*2;
    int cfuel=p[n-1];
    while (minbound<maxbound){
        cfuel = minbound +(maxbound-minbound)/2;
        if (checkValid(p,f,cfuel,kval)) maxbound=cfuel;
        else minbound=cfuel+1;
    }
    cfuel = minbound +(maxbound-minbound)/2;
    cout<<cfuel<<endl;
    return 0;
}
