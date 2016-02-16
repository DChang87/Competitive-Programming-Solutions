/*
There is a very unusual street in your neighbourhood. This street forms a perfect circle, and the circumference of 
the circle is 1,000,000. There are H (1 ≤ H ≤ 1000) houses on the street. The address of each house is the clockwise 
arc-length from the northern-most point of the circle. The address of the house at the northern-most point of the circle is 0.
You also have special firehoses which follow the curve of the street. However, you wish to keep the length of the longest 
hose you require to a minimum.
Your task is to place k (1 ≤ k ≤ 1000) fire hydrants on this street so that the maximum length of hose required to 
connect a house to a fire hydrant is as small as possible.
Input
The first line of input will be an integer H, the number of houses. The next H lines each contain one integer, 
which is the address of that particular house, and each house address is at least 0 and less than 1,000,000. 
On the H+2nd line is the number k, which is the number of fire hydrants that can be placed around the circle. 
Note that a fire hydrant can be placed at the same position as a house. You may assume that no two houses are at the same address. 
*/
#include<bits/stdc++.h>
using namespace std;
int N,K; int houses[1010]; int MAX=1000000;
int main()
{
    cin>>N;
    for (int i=0;i<N;i++) cin>>houses[i];
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
        while (right>left+1){ //binary search
            hoseCount=1;
            hoseLength = (left+right)/2;
            int hydrantPos = hoseLength;
            for (int i=0;i<N;i++){
                if (houses[i]>hydrantPos+hoseLength && MAX-hoseLength>houses[i]){
                    hoseCount++;
                    hydrantPos = houses[i]+hoseLength;
                }
            }
            if (hoseCount<=K){ right = hoseLength;}
            else{ left = hoseLength;}
        }
        maxRequired = max(maxRequired,right);
    }
    cout<<maxRequired<<endl;
}
