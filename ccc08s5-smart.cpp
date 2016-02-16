/*
Canada's top two nuclear scientists, Patrick and Roland, have just completed the construction of the world's 
first nuclear fission reactor. Now it is their job to sit and operate the reactor all day, every day. 
Naturally they got a little bored after doing this for a while and as a result, two things have happened. 
First, they can now control the individual reactions that happen inside the reactor. Second, to pass the time, 
they have invented a new game called Nukit.
At the beginning of Nukit, a number of particles are put in the reactor. The players take alternating turns, 
with Patrick always going first. When it is a player's turn to move, they must select some of the remaining 
particles to form one of the possible reactions. Then those particles are destroyed. Eventually there will 
be so few particles that none of the reactions can be formed; at this point, the first person who is unable 
to form a reaction on their turn loses.
In our universe you can assume that there are only 4 types of particles: A, B, C, D. Each reaction is a list 
of particles that can be destroyed on a single turn. The five reactions are:
AABDD       ABCD        CCD     BBB         AD
For example, the first reaction "AABDD" says that it is allowable to destroy two A, one B, and two 
D particles all at the same time on a turn.
It turns out that, no matter how many particles start off in the reactor, exactly one of Patrick 
or Roland has a perfect winning strategy. By player X has a perfect winning strategy, we mean 
that no matter what the other player does, player X can always win by carefully choosing reactions. 
For example, if the reactor starts off with one A, five B, and three D particles then Roland has the 
following perfect winning strategy: "if Patrick forms reaction BBB initially, then form reaction AD 
afterward; if Patrick forms reaction AD initially, then form reaction BBB afterward." (The strategy 
works because either way, on Patrick's second turn, there are not enough particles left to form any reactions.)
Given the number of each type of particle initially in the reactor, can you figure out who has a perfect winning strategy?
*/
#include<iostream>
#include<cstdio>
using namespace std;
bool winp[31][31][31][31];
int valid[5][4]= {{2,1,0,2},{1,1,1,1},{0,3,0,0},{1,0,0,1},{0,0,2,1}};
bool iflosing(int a,int b,int c,int d)
{
    if (a<0||b<0||c<0||d<0) return false;
    return !winp[a][b][c][d];
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
        if (winp[q][r][s][t]) cout<<"Patrick"<<endl;
        else{cout<<"Roland"<<endl;}
    }
}
