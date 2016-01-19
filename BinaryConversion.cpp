#include <iostream>
#include <bitset>
using namespace std;
string binary;
int main()
{
    int n;
    char holder=' ';
    cin>>n;
    while (n!=0){
        holder = n%2+'0';
        binary = holder+binary;
        n/=2;
    }
  return 0;
}
