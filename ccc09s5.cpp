/*
Bob is sitting at home with his computer. He would like to experience more social interaction, 
so he is planning a trip to a coffee shop with his computer.
Bob has lots of data about wireless networks and coffee shops in the city. In Bob's city, there is one coffee shop 
at every intersection of streets. Specifically, Bob happens to live in a city with M streets (1 ≤ M ≤ 30,000) that 
run east and west, and N streets (1 ≤ N ≤ 1,000) that run north and south. As an added benefit, the distance between 
consecutive parallel streets is 1 metre (it is a very compact city).
It also turns out that inside K (1 ≤ K ≤ 1,000) of the coffee shops, there is a wireless network station. Each wireless 
network station will have a particular bitrate B (1 ≤ B ≤ 1,000) and can reach R metres (1 ≤ R ≤ 30,000) from the coffee 
shop. In other words, a wireless network station from one coffee shop forms a circle with radius R centered at that 
particular coffee shop. Moreover, if someone is at distance R, the wireless network would be available, but if someone 
is at a distance larger than R, they cannot access that wireless point.
You can assume that each coffee shop has at most one wireless network stationed in it, but that multiple wireless networks 
may be available while sitting in that one coffee shop, due to the proximity of other wireless network stations.
Bob has a special device in his computer that can use all of the available bitrates of as many wireless networks as he can connect to.
Bob would like to find out the maximum bitrate he can obtain, and how many coffee shops would have that maximum capacity.
*/
#include<bits/stdc++.h>
using namespace std;
int X,Y,K; //M,N,K
int MAX=0; int diff[30010][1010];
int main()
{
    cin>>X>>Y>>K;
    int x,y,r,b;
    /* The first integer x on each line represents the north-south street on which the coffee shop is located, where 1 ≤ x ≤ N. 
    The second integer, y, on each line represents the east-west street on which the coffee shop is located, where 1 ≤ y ≤ M. 
    The third integer, R, on each line represents the radius of the wireless network from this particular coffee shop. 
    The fourth integer, B, on each line represents the bitrate of the wireless network from this particular coffee shop.*/
    for (int i=0;i<K;i++){
        cin>>y>>x>>r>>b; x--;y--;
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
            if (i!=0){ diff[i][j]+=diff[i-1][j];}
            if (diff[i][j]==MAX){ counter++;}
            if (diff[i][j]>MAX){
                MAX = diff[i][j];
                counter=1;
            }
        }
    }
    cout<<MAX<<endl;
    cout<<counter<<endl;
}
