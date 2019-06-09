#include<iostream>
using namespace std;


int main(){

	int arr[] = {1,2,3,-1,4,-2,5,6,-4,2};
	int n = sizeof(arr)/sizeof(int);

	//Kadane's Algorithm -> Max Subarray Sum in O(N) time
	int cs  = 0,ms = 0;
	for(int i=0;i<n;i++){
		int cs += arr[i];
		if(cs<0){
			cs = 0;
		}
		ms = max(ms,cs);
	}
	cout<<ms<<endl;

	return 0;
}
