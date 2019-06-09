#include<iostream>
using namespace std;

int power(int a,int n){
	//base case 
	if(n==0){
		return 1;
	}
	//rec case
	int smallAns = power(a,n/2);
	smallAns *= smallAns;

	if(n&1){
		return a*smallAns;
	}
	return smallAns;
}

int fastPowerBitmasking(int a,int n){

	int ans = 1;
	while(n>0){
		if(n&1){
			ans *= a;
		}
		a *= a;
		n >>=1;
	}
	return ans;

}


int main(){

	cout<<fastPowerBitmasking(5,3)<<endl;

	return 0;
}