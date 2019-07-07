#include<iostream>
#include<climits>
using namespace std;

int csum(int a[],int i,int j){
	int s = 0;
	for(int k=i;k<=j;k++){
		s += a[k];
		s = s%100;
	}
	return s;
}


int mixtures(int a[],int i,int j,int dp[][10]){
	//Base Case
	if(i>=j){
		return dp[i][j]=0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	//Rec Case
	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		int cans = mixtures(a,i,k,dp) + mixtures(a,k+1,j,dp) + csum(a,i,k)*csum(a,k+1,j);
		ans = min(ans,cans);
	}
	return dp[i][j]=ans;

}

int main(){
	int dp[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			dp[i][j] = -1;
		}
	}

	int mix[] = {40,60,20};
	int n = 3;

	cout<<mixtures(mix,0,n-1,dp)<<endl;

	//print the dp array
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}