//DP, sorting


//create every possible distance between pairs
//sort it (along with the two points in the pair
//go through each pair, checking with the two points (and the distances required previous to travel to the two points
//since the pairs vector is already sorted, just have to check if the distances are equivalent
//if theyre not, that means that the new distance (the distance for the current pair) is greater
/* and we can use this distance to travel to the point
check if the current # of treats for the point is better
or 1 + the current # of treats for the other point is
(current treat is better or we can receive a better result traveling from the other point
 save the best result
 if a==0 (origin)
only store the best of the current best[a] or the # of treats traveling from point B
this really only stores the best number of treats you can get going through 0 (and you must)
add 1 at the end because the end point wasn't couted for treats? (????)
*/
                                                

#include<bits/stdc++.h>
using namespace std;
int N;
int coords[2010][2];
int best[2010][3]; //best, best@point, bestdistance
vector<pair<int,pair<int,int>>> pairs;
int dp[2010];
int dist(int x1,int y1, int x2, int y2)
{
    return pow(x1-x2,2)+pow(y1-y2,2);
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    coords[0][0]=0;
    coords[0][1]=0;
    for (int i=1;i<=N;i++){
        cin>>coords[i][0]>>coords[i][1];
    }
    for (int i=0;i<=N;i++){
        for (int j=i+1;j<=N;j++){
            pairs.push_back(make_pair(dist(coords[i][0],coords[i][1],coords[j][0],coords[j][1]),make_pair(i,j)));
        }
    }
    sort(pairs.begin(),pairs.end());
    int d,a,b;
    for (int i=0;i<pairs.size();i++){
        d = pairs[i].first;
        a = pairs[i].second.first;
        b = pairs[i].second.second;
        if (d!=best[a][2]) //if d is greater than the distance already accounted previously to A
        {
            best[a][1] = best[a][0]; //temporary best at point A can be equated as the current best at A
            best[a][2] = d;
        }
        if (d!=best[b][2]){
            best[b][1] = best[b][0];
            best[b][2]=d;
        }
        if (a==0){ //origin cannot be revisited, only keep track of it
                //to keep track of best possible #of treats used that passed through the origin
            best[a][0] = max(best[a][0],best[b][1]);
        }
        else{ //take the best possible # of treats (either the original #, or the # from B + 1 (travelling to A)
            best[a][0]=max(best[a][0],best[b][1]+1);
            best[b][0]=max(best[b][0],best[a][1]+1);
        }
    }
    cout<<best[0][0]+1; //bc the last treat wasn't accounted for in the calculation
}
