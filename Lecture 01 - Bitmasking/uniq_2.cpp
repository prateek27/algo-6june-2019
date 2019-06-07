#include<iostream>
using namespace std;

using namespace std;

int main(){
	int arr[] = {1,2,1,3,3,4,4,6,5,7,5,6}; //two and seven
	int sabka_xor = 0;
	int n = sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++){
			sabka_xor ^= arr[i];
	}
	int temp = sabka_xor;
	int p = 0;
	while(temp>0){
		int last_bit = temp&1;
		if(last_bit==1){
			break;
		}
		p++;
		temp = temp>>1;
	}
	//filter out two sets - 
	int setA = 0;
	for(int i=0;i<n;i++){
		if((a[i]&(1<<p))>0){
			setA ^= a[i];
		}
	}
	int setB = sabka_xor^setA;
	cout<<setA<<" and "<<setB<<endl;


	return 0;
}