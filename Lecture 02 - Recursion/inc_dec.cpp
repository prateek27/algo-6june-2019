#include<iostream>
using namespace std;

int inc(int n){
	if(n==0){
		return;
	}
	inc(n-1);
	cout<<n<<" ";

}
int dec(int n){
	if(n==0){
		return;
	}
	cout<<n<<" ";
	dec(n-1);

}


int main(){

	int n = 5;

	return 0;
}