/*
The director of Hind Circus has decided to add a new performance, the monkey dance, to his show. The monkey dance is performed 
simultaneously by N monkeys. There are N circles drawn on the ground, labelled from 1 to N. In the beginning, each monkey sits 
on a different circle. There are N arrows drawn from circle to circle in such a way that there is exactly one arrow pointing 
toward each ring and exactly one arrow pointing away from each ring.
When the show begins, at each whistle of the ringmaster, all the monkeys simultaneously jump from their respective circles to 
other circles following the arrows from their respective current circles. This is one step of the dance. The dance ends when 
all the monkeys have returned to the circles where they initially started. How long does the dance last?
Input
The input may have multiple cases.
Each case consists of the value of N (1 ≤ N ≤ 100) on a line, followed by N lines, each with a pair of integers between 1 and N. 
The pair I1, I2 means that there is an arrow from circle I1 to circle I2. The input ends with 0 for the value of N.*/
#include<bits/stdc++.h>
using namespace std;
int N,a,b;
int gcd(int a,int b){
    while (b>0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int lcm(int a,int b){
    return a * (b/gcd(a,b));
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    while (N!=0){
        int path[N];
        for (int i=0;i<N;i++){
            cin>>a>>b;
            a--;b--;
            path[a]=b;
        }
        bool visited[N];
        vector<int> len;
        memset(visited,false,sizeof visited);
        for (int i=0;i<N;i++){
            if (visited[i])continue;
            visited[i]=true;
            int cur=i;
            int counter=1;
            while (true){
                cur = path[cur];
                visited[cur] = true;
                if (cur==i){
                    len.push_back(counter);
                    break;
                }
                counter++;
            }
        }
        int num=1;
        for (int i=0;i<len.size();i++){
            num = lcm(num,len[i]);
        }
        cout<<num<<endl;
        cin>>N;
    }
    return 0;
}
