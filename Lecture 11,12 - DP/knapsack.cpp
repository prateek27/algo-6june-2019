#include<iostream>
#include<climits>
using namespace std;

int knapsack(int w[],int prices[],int n,int C,int dp[][100]){
	//Base Case
	if(n==0 or C==0){
		return 0;
	} 
	if(dp[n][C]!=0){
		return dp[n][C];
	}
	//Rec Case
	int inc,exc;
	inc = exc = INT_MIN;

	if(C-w[n-1]>=0){
		inc = prices[n-1] + knapsack(w,prices,n-1,C-w[n-1],dp);
	}
	exc = knapsack(w,prices,n-1,C,dp);
	return dp[n][C] = max(inc,exc);
}

int knapsackBottomUp(int wt[],int prices[],int n,int C){

	int dp[100][100] = {0};

	for(int i=0;i<=n;i++){
		for(int w=0;w<=C;w++){
			if(i==0 or w==0){
				dp[i][w] = 0;
			}
			else{
				int inc,exc;
				inc  = exc = INT_MIN;
				if(w-wt[i-1]>=0){
					inc = prices[i-1] + dp[i-1][w-wt[i-1]];
				}
				exc = dp[i-1][w];
				dp[i][w] = max(inc,exc);
			}
			cout<<dp[i][w]<<" ";
		}
		cout<<endl;
	}
	return dp[n][C];
}

int main(){
	
	int dp[100][100] = {0};
	int prices[] = {50,30,40,80};
	int w[] = {5,2,1,7};
	int n = 4;
	cout<<knapsack(w,prices,n,7,dp)<<endl;
	cout<<knapsackBottomUp(w,prices,n,7)<<endl;



	return 0;
}