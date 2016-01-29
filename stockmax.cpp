#include<bits/stdc++.h>
using namespace std;
int N,n,stocks[50010],maxPrice[50010];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>n;
        for (int j=0;j<n;j++){
            cin>>stocks[j];
            maxPrice[j]=stocks[j];
        }
        for (int j=n-2;j>=0;j--){
            maxPrice[j] = max(maxPrice[j],maxPrice[j+1]);
        }
        int gains=0;
        for (int j=0;j<n;j++){
            gains+= (maxPrice[j]-stocks[j]);
        }
        cout<<gains<<endl;
    }
    return 0;
}


