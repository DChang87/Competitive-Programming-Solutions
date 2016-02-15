#include<bits/stdc++.h>
using namespace std;
int N,K;
int houses[1010];
int MAX=1000000;
int main()
{
    cin>>N;
    for (int i=0;i<N;i++){
        cin>>houses[i];
    }
    cin>>K;
    if (K>=N){
        cout<<0<<endl;
        return 0;
    }
    sort(houses,houses+N);
    //go through each house
    //find the shortest length at each house
    //find the longest out of the shortest lengths
    int tempHouse;
    int maxRequired=0;
    for (int j=0;j<N;j++){
        //shift all the houses by the house at index 0
        tempHouse = houses[0];
        for (int i=0;i<N;i++){
            houses[i]=houses[i+1]-tempHouse;
        }
        int left=0,right=MAX;
        int hoseLength, hoseCount;
        //binary search
        while (right>left+1){
            hoseCount=1;
            hoseLength = (left+right)/2;
            int hydrantPos = hoseLength;
            for (int i=0;i<N;i++){
                if (houses[i]>hydrantPos+hoseLength && MAX-hoseLength>houses[i]){
                    hoseCount++;
                    hydrantPos = houses[i]+hoseLength;
                }
            }
            if (hoseCount<=K){
                right = hoseLength;
            }
            else{
                left = hoseLength;
            }
        }
        maxRequired = max(maxRequired,right);
    }
    cout<<maxRequired<<endl;
}
