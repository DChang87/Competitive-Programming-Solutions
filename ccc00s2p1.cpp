//maps, vectors, pointers
/*In this problem, you will write a program to find the minimal solution to a set of set inequalities.
A set inequality has the format             X contains S
where X may be any set name and S may be a set name or set element. If S is a set name the inequality means 
that X is a superset or equal to S. If S is an element the inequality means that X contains S. Sets are named A-Z 
and contain elements from a-z.*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int N;
map<char,vector<char>> storage;
int main()
{
    cin>>N;
    char instr[N][2];
    string cont;
    int val;
    for (int i=0;i<N;i++){
        cin>>instr[i][0]>>cont>>instr[i][1];
        if (storage.find(instr[i][0])==storage.end()){
            storage[instr[i][0]];
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            val = instr[j][1];
            if (65<=val && val<=90){
                for (int k=0;k<storage[instr[j][1]].size();k++){
                    if (find(storage[instr[j][0]].begin(),storage[instr[j][0]].end(),storage[instr[j][1]][k])==storage[instr[j][0]].end()){
                        storage[instr[j][0]].push_back(storage[instr[j][1]][k]);
                    }
                }
            }
            else{
                if (find(storage[instr[j][0]].begin(),storage[instr[j][0]].end(),instr[j][1])==storage[instr[j][0]].end()){
                    storage[instr[j][0]].push_back(instr[j][1]);
                }
            }
        }
    }
    map<char,vector<char>>::iterator it;
    for (it = storage.begin();it!=storage.end();it++){
        cout<<it->first<<" = ";
        cout<<"{";
        sort(it->second.begin(),it->second.end());
        for (int i=0;i<it->second.size();i++){
            if (i!=0){
                cout<<",";
            }
            cout<<it->second[i];
        }
        cout<<"}"<<endl;
    }
}
