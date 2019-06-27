#include<iostream>
using namespace std;


void heapify(int *arr,int i,int n){
	
	int left = i<<1;
	int right = left+1;

	int mx_idx = i;
	if(left<n and arr[i]<arr[left]){
		mx_idx = left;
	}
	if(right<n and arr[mx_idx]<arr[right]){
		mx_idx = right;
	}
	if(i!=mx_idx){
		swap(arr[i],arr[mx_idx]);
		heapify(arr,mx_idx,n);
	}
}


int main(){
	int arr[] = {-1,5,4,1,2,3,0};
	int n = sizeof(arr)/sizeof(int);

	//Convert Array into Heap --> O(N)
	for(int i=n/2;i>=1;i--){
		heapify(arr,i,n);
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	//remove the elements top --> last 

	

	return 0;
}