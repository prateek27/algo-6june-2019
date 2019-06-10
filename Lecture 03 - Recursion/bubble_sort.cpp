#include<iostream>
using namespace std;


void bubbleSort(int *arr,int i,int n){
	//base case
	if(n<=1){
		return;
	}

	//rec case
	if(i==n-1){
		bubbleSort(arr,0,n-1);
		return;
	}
	if(arr[i]>arr[i+1]){
		swap(arr[i],arr[i+1]);
	}
	bubbleSort(arr,i+1,n);

}


int main(){

	int arr[] = {4,3,2,0,1};
	int n = 5;
	//bubble sort
	bubbleSort(arr,0,n);
	//print sorted array
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}