/*
WallE256 and ionutpop118 are playing GG games of Hearthstone! Hearthstone is a card game in which two players 
duke it out with minions, spells, and secrets. To keep their game simple, they've decided to use minions only and play 
according to the following rules:
-Each player starts the game with 30 health
-Each player can have no more than 7 minions on the board
-Each minion has two stats - its attack and health
-Each minion can only attack once per turn, if it attacks another minion, both lose health equivalent to the other's 
-attack, if it attacks the opponent directly, the opposing player loses health equivalent to the minion's attack
-A minion dies if its health reaches 0 or below, similarly, a player wins if the opponent's health reaches 0 or below
-Opponent minions with the special effect taunt must be killed first before attacking the opponent player
A player is considered to have lethal if they can win the game in that turn.
does he have lethal?
The first line of input will contain G, the number of games they play. (1≤G≤5)
The second line of each game will contain N (0≤N≤7), the number of minions WallE256 has on the board.
The third line of each game will contain N space-separated integers, the attack values of WallE256's minions. 
Attack values will be no greater than 12.
The fourth line of each game will contain two space-separated integers, Hi(1≤Hi≤30) and Hm(1≤Hm≤12), ionutpop118's 
health and his taunt minion's health, respectively.
*/
#include <bits/stdc++.h>
using namespace std;
int atk[50];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int G, N;
    cin >> G;
    while (G--){
        cin >> N;
        int totatk = 0;
        int hp1, hp2;
        for (int i=0; i<N; ++i){
            cin >> atk[i]; totatk+=atk[i];
        }
        cin >> hp1 >> hp2;
        bool flag = false;
        for (int i=0; i<(1<<N); ++i){
            int mask = i, dmg1=0, dmg2=0;
            for (int j=0; j<N; ++j){
                if (mask%2 == 0){ dmg1+=atk[j];}
                else{  dmg2+=atk[j];}
                mask/=2;
            }
            if (dmg1 >= hp1 && dmg2 >= hp2){
                cout << "LETHAL" << endl;
                flag = true;break;
            }
        }
        if (flag) continue;
        cout << "NOT LETHAL" << endl;
    }
    return 0;
}
