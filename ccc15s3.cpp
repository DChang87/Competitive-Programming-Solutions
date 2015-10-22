#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int G, P; cin >> G >> P;
    set<int> gates;
    for (int i=1; i<=G; ++i) gates.insert(i); //insert the spots in the gates set
    int ans = 0;
    while (ans < P){
        int p;
        cin >> p;
        if (gates.upper_bound(p)==gates.begin()) break; //if there are no spots greater than p, no more available spots
        gates.erase(--gates.upper_bound(p)); //remove the greatest possible spot for p
        ans++;
    }
    cout << ans;
    return 0;
}
