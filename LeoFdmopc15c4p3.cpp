#include <bits/stdc++.h>

using namespace std;

int atk[50];

int main()
{
//    freopen("DMOPC.txt","r",stdin);
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
                if (mask%2 == 0){
                    dmg1+=atk[j];
                }
                else{
                    dmg2+=atk[j];
                }
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
