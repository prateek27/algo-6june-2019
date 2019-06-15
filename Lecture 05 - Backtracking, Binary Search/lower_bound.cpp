#include<iostream>
using namespace std;

int lower_bound(int *arr,int n,int key){

	int s=0;
	int e=n-1;
	int ans = -1;
	while(s<=e){
		int mid  = (s+e)/2;
		if(arr[mid]==key){
			ans = mid;
			e = mid - 1; //s = mid + 1;
		}
		else if(arr[mid]>key){
			e = mid -1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int main(){

	int arr[] = {1,2,2,2,2,2,3,3,3,3,4};
	int n = sizeof(arr)/sizeof(int);

	cout<<lower_bound(arr,n,2)<<endl;




	return 0;
}