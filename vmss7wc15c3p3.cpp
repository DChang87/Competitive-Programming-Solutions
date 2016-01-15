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
    if (k<0){
        return false;
    }
    return true;
}
int main()
{
    cin>>n>>kval;
    long long p[n+1],f[n+1];
    long long P,F;
    //long long optimal=p[n-1];
    long long fringes=0;
    p[0]=0;
    f[0]=0;
    bool fringy=false;
    for (long long i=0;i<n;i++){
        cin>>P>>F;
        if (F==1 || i==n-1){
            fringes++;
        }
        p[i+1]=P;
        f[i+1]=F;
        if (fringes>kval){
            fringy=true;
        }
    }
    if (fringy){
        cout<<"DEA Bust!"<<endl;
        return 0;
    }
    int minbound=0,maxbound=p[n]*2;
    int cfuel=p[n-1];
    while (minbound<maxbound){
        cfuel = minbound +(maxbound-minbound)/2;
        if (checkValid(p,f,cfuel,kval)){
            maxbound=cfuel;
        }
        else{
            minbound=cfuel+1;
        }

    }
    cfuel = minbound +(maxbound-minbound)/2;
    cout<<cfuel<<endl;
    return 0;
}
