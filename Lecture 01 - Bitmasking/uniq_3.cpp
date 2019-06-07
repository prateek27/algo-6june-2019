#include<iostream>
using namespace std;


int main(){

	int arr[] = {1,2,1,2,3,2,1,4,4,5,4,5,5};
	int freq[64] = {0};
	int n = sizeof(arr)/sizeof(int);

	for(int i=0;i<n;i++){
		int temp = arr[i];
		int p = 0;
		while(temp>0){
			if((temp&1)==1){
				freq[p]++;
			}
			p = p + 1;
			temp = temp>>1;
		}
	}
	int tp = 1;
	int ans = 0;
	for(int i=0;i<64;i++){
			ans += (freq[i]%3)*tp;
			tp = tp<<1;
	}
	cout<<ans<<endl;



	return 0;
}