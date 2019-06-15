#include<iostream>
using namespace std;

bool canPlace(int n,int *stalls,int C,int sep){

	int cows_placed =1;
	int last_placed_cow = stalls[0];
	//remaining stalls 
	for(int i=1;i<n;i++){
		int c_stall = stalls[i];
		if(c_stall-last_placed_cow>=sep){
			cows_placed++;
			last_placed_cow = c_stall;
			if(cows_placed==C){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n=5;
	int stalls[] = {1,2,4,8,9}; //sort 
	int cows = 3;

	int s=0;
	int e = stalls[n-1] - stalls[0];
	int ans = 0;
	while(s<=e){
		int mid = (s+e)/2;
		if(canPlace(n,stalls,cows,mid)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}

	}
	cout<<ans<<endl;
	return 0;
}