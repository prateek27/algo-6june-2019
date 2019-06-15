#include<iostream>
using namespace std;

bool canPlace(int a[][10],int i,int j,int no,int n){
	//row col
	for(int x=0;x<n;x++){
		if(a[x][j]==no or a[i][x]==no){
			return false;
		}
	}
	//subgrid
	int sx = 3*(i/3);
	int sy = 3*(j/3);

	for(int x=sx;x<sx+3;x++){
		for(int y=sy;y<sy+3;y++){
			if(a[x][y]==no){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int a[][10],int i,int j,int n){
	//base case
	if(i==n){
		//print the matrix
		return true;
	}
	//corner cases
	if(j==n){
		return solveSudoku(a,i+1,0,n);
	}
	if(a[i][j]!=0){
		return solveSudoku(a,i,j+1,n);
	}
	//rec case 
	for(int k=1;k<=n;k++){
		if(canPlace(a,i,j,k,n)){
			a[i][j] = k;
			bool aageKaSolveHua = solveSudoku(a,i,j+1,n);
			if(aageKaSolveHua){
				return true;
			}
		}
	}

	a[i][j] = 0; //backtracking
	return false;
}


int main(){
	int n=9;
	int a[10][10];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	solveSudoku(a,0,0,9);
	
	//Print Matrix!
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}




	return 0;
}