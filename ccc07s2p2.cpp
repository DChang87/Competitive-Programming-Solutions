/*
You may have heard that no two snowflakes are alike. Your task is to write a program to determine whether this is really true. Your program will read information about a collection of snowflakes, and search for a pair that may be identical.

Each snowflake has six arms. For each snowflake, your program will be provided with a measurement of the length of each of the six arms. Any pair of snowflakes which have the same lengths of corresponding arms should be flagged by your program as possibly identical.
*/
#include<bits/stdc++.h>
using namespace std;
int N,flake[6]; string str; set<string> SFs;
int main(){
    scanf("%d",&N);
    for(int i = 0;i < N;++i){
        scanf("%d%d%d%d%d%d",&flake[0],&flake[1],&flake[2],&flake[3],&flake[4],&flake[5]);
        sort(flake,flake+6);
        str = "";
        for(int j = 0;j < 6;j++){
            str += static_cast<ostringstream*>( &(ostringstream() << flake[j]) )->str();
        }
        if (SFs.find(str)!=SFs.end()){
            printf("Twin snowflakes found. \n");
            return 0;
        }
        else SFs.insert(str);
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
