#include<iostream>
using namespace std;

bool isSafe(int board[][10],int x,int y,int n){
	//column 
	for(int i=0;i<x;i++){
		if(board[i][y]==1){
			return false;
		}
	}
	//Left Diagonal
	int a = x,b=y;
	while(a>=0 and b>=0){
		if(board[a][b]==1){
			return false;
		}
		a--;
		b--;
	}
	//right diagonal
	a=x,b=y;
	while(a>=0 and b<n){
		if(board[a][b]==1){
			return false;
		}
		a--;
		b++;
	}
	return true;
}

void solveNQueen(int n,int board[10][10],int i){
	//base case
	if(i==n){
		//print the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	//rec case
	for(int j=0;j<n;j++){
		if(isSafe(board,i,j,n)){
			board[i][j] = 1;
			solveNQueen(n,board,i+1);
		}
		board[i][j] = 0;
	}
}


int main(){
	int board[10][10] = {0};
	int n;
	cin>>n;
	solveNQueen(n,board,0);




	return 0;
}