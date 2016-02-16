//rounding, mergeSort
/*
Pinball is an arcade game in which an individual player controls a silver ball by means of flippers, with the 
objective of accumulating as many points as possible. At the end of each game, the player's score and rank are displayed. 
The score, an integer between 0 and 1 000 000 000, is that achieved by the player in the game just ended. The rank is displayed 
as "r of n". n is the total number of games ever played on the machine, and r is the position of the score for the just-ended 
game within this set.
More precisely, r is one greater than the number of games whose score exceeds that of the game just ended.
Input
You are to implement the pinball machine's ranking algorithm. The first line of input contains a positive integer, t, 
the total number of games played in the lifetime of the machine. t lines follow, given the scores of these games, in 
chronological order.
*/
#include <bits/stdc++.h>
using namespace std;
double total=0;
int pins[100001],newPins[100001];
int N;
void merge(int left, int mid, int right)
{
    int pos1 = left;
    int pos2 = mid+1;
    int newpos = 0;
    while (pos1<=mid && pos2<=right){
        if (pins[pos1]<=pins[pos2]){
            newPins[newpos]=pins[pos1];
            pos1++;
            newpos++;
        }
        else{
            newPins[newpos]=pins[pos2];
            pos2++;
            newpos++;
            total += mid+1-pos1;
        }
    }
    while (pos1<=mid){
        newPins[newpos]=pins[pos1];
        newpos++;
        pos1++;
    }
    while (pos2<=right){
        newPins[newpos]=pins[pos2];
        newpos++;
        pos2++;
    }
    for (int pos1=left;pos1<=right;pos1++){
        pins[pos1]=newPins[pos1-left];
    }
}
void mergeSort(int left,int right)
{
    //keep calling merge() on the left and right halves of the array
    if (left<right){
        int mid = (left+right)/2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        merge(left,mid,right);
    }
}
int main()
{
    cin>>N;
    for (int i=0;i<N;i++) cin>>pins[i];
    mergeSort(0,N-1);
    printf("%.2f", double(total + N) / N);
}
