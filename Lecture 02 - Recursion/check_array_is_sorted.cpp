#include<iostream>
using namespace std;

bool isSorted(int *arr,int n){
	//Base Case
	if(n==1){
		return true;
	}
	//Rec Case
	if(a[0]<a[1] and isSorted(arr+1,n-1)){
		return true;
	}
	return false;

}


int main(){

	int arr[] = {1,2,3,4,5,3,6};
	int n = sizeof(arr)/sizeof(int);



	return 0;
}