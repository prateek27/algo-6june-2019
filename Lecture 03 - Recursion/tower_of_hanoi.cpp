#include<iostream>
using namespace std;

int toh(int n){
	if(n==1){
		return 1;
	}
	return 2*toh(n-1)+1;
}


int main(){

	int n;
	cin>>n;
	cout<<toh(n)<<endl;

	return 0;
}