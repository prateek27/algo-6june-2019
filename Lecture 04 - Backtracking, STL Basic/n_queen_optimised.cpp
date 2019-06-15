#include<iostream>
using namespace std;

int L[40]={0},R[40]={0},C[40]={0};

int cntNQueen(int n,int i){
	if(i==n){ 
		return 1;
	}
	//rec case
	int cnt = 0;
	for(int j=0;j<n;j++){
		if(C[j]==0 and L[i-j+(n-1)]==0 and R[i+j]==0){
			C[j] = L[i-j+(n-1)] = R[i+j] = 1;
			cnt += cntNQueen(n,i+1);
			C[j] = L[i-j+(n-1)] = R[i+j] = 0;		
		}
	}
	return cnt;
}


int main(){
	int n;
	cin>>n;
	cout<<cntNQueen(n,0)<<endl;
	return 0;
}