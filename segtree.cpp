//The following M lines contain one operation each. Each operation is either of the form M i x, 
//indicating that element number i (0 ≤ i < N) is to be changed to x (0 ≤ x < 1 000 000), or the form Q i j (0 ≤ i ≤ j < N) 
//indicating that your program is to find the minimum value of the elements in the index range [i, j] (that is, inclusive) 
//in the current state of the array and print this value to standard output.

/*
#include <bits/stdc++.h>

using namespace std;

int N,M, val[100005],seg[300005],a,b,LL,RR;
char instr;

void build_tree(int index, int L, int R)
{
    if (L==R){
        seg[index] = val[L];
        return;
    }
    int mid = (L+R)/2;
    build_tree(index*2+1,mid+1,R);
    build_tree(index*2,L,mid);
    seg[index] = min(seg[index*2+1],seg[index*2]);
}

void update(int index, int pos, int L, int R)
{
    if (L==R){
        seg[index] = val[pos];
        return;
    }
    int mid = (L+R)/2;
    if (pos<=mid){
        update(index*2,pos,L,mid);
    }
    else{
        update(index*2+1,pos,mid+1,R);
    }
    seg[index] = min(seg[index*2],seg[index*2+1]);
}

int query(int index, int L, int R)
{
    if (R<LL || RR<L){
        return 1e9;
    }
    if (LL<=L && R<=RR) return seg[index];
    int mid = (L+R)/2;
    return min(query(index*2,L,mid),query(index*2+1,mid+1,R));
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for (int i=0;i<N;i++){
        cin>>val[i];
    }
    build_tree(1,0,N-1);
    for (int i=0; i!=M; ++i){
        cin >> instr >> LL >> RR;
        if (instr == 'Q'){
            cout << query(1,0,N-1) << '\n';
        }
        else if (instr == 'M'){
            val[LL] = RR;
            update(1,LL,0,N-1);
        }
    }
}

*/
