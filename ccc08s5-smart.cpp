#include<iostream>
#include<cstdio>
using namespace std;

bool winp[31][31][31][31];
int valid[5][4]= {{2,1,0,2},{1,1,1,1},{0,3,0,0},{1,0,0,1},{0,0,2,1}};
bool iflosing(int a,int b,int c,int d)
{
    if (a<0||b<0||c<0||d<0){
        return false;
    }
    else{
        return !winp[a][b][c][d];
    }
}
int main()
{
    for (int a=0;a<31;a++){
        for (int b=0;b<31;b++){
            for (int c=0;c<31;c++){
                for (int d=0;d<31;d++){
                    winp[a][b][c][d]=false;
                }
            }
        }
    }
    for (int a=0;a<31;a++){
        for (int b=0;b<31;b++){
            for (int c=0;c<31;c++){
                for (int d=0;d<31;d++){
                    for (int i=0;i<5;i++){
                        if (iflosing(a-valid[i][0],b-valid[i][1],c-valid[i][2],d-valid[i][3])){
                            winp[a][b][c][d]=true;
                        }
                    }
                }
            }
        }
    }
    int n,q,r,s,t;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d%d%d",&q,&r,&s,&t);
        if (winp[q][r][s][t]){
            cout<<"Patrick"<<endl;
        }
        else{
            cout<<"Roland"<<endl;
        }
    }
}
