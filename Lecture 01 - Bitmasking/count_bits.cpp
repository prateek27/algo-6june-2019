#include <iostream>
using namespace std;
// LogN Steps
int count_bits(int n){
    int ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}
//efficent way to computer number of set bits
int fun(int n){
    int ans = 0;
    while(n>0){
       ans++;
       n = (n&(n-1)); 
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    cout<<count_bits(n)<<endl;
    cout<<fun(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;

    return 0;
}
