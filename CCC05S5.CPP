//rounding, mergeSort

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
    for (int i=0;i<N;i++){
        cin>>pins[i];
    }
    mergeSort(0,N-1);
    printf("%.2f", double(total + N) / N);
}
