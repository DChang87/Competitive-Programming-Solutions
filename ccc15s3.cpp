//clever use of sets
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int G, P; cin >> G >> P; //number of gates, number of planes to park
    set<int> gates;
    for (int i=1; i<=G; ++i) gates.insert(i); //insert the spots in the gates set
    int ans = 0;
    while (ans < P){
        int p;
        cin >> p; //plane number to be parked
        //gates.upper_bound(p) returns the least value in gates that is greater than p
        //if that upper_bound(p) is where the set begins
        //there are no spots that can be parked (no spots less than or equal to p)
        if (gates.upper_bound(p)==gates.begin()) break; //if there are no spots greater than p, no more available spots
        cout<<*gates.upper_bound(p)<<endl;
        gates.erase(--gates.upper_bound(p)); //remove the greatest integer in the set that is less than the upper_bound(p)
        ans++;
    }
    cout << ans;
    return 0;
}
