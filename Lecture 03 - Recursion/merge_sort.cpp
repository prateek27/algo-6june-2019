#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
	int mid = (s+e)/2;
	int i =s;
	int j =mid+1;
	int k=s;

	int temp[100];

	while(i<=mid and j<=e){
		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			i++; k++;
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	//put another loop
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	//copy back elements to orignal array a
	for(int i=s;i<=e;i++){
		arr[i] = temp[i];
	}

}

void mergeSort(int arr[],int s,int e){
	//Base Case
	if(s>=e){
		return;
	}
	//Rec Case
	int mid = (s+e)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	merge(arr,s,e);
	return;
}


int main(){

	int arr[] = {3,1,2,6,5,0};
	int n = sizeof(arr)/sizeof(int);
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}