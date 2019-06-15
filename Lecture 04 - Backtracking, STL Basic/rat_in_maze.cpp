#include<iostream>
using namespace std;

bool pathExists(char maze[][10],int i,int j,int m,int n){
	//base case
	if(i==m and j==n){
		return true;
	}
	if(i>m or j>n){
		return false;
	}
	if(maze[i][j]=='X'){
		return false;
	}

	bool rightSeRastaMila = pathExists(maze,i,j+1,m,n);
	if(rightSeRastaMila){
		return true;
	}
	return pathExists(maze,i+1,j,m,n);
}

int cntPath(char maze[][10],int i,int j,int m,int n){
	//base case
	if(i==m and j==n){
		return 1;
	}
	if(i>m or j>n){
		return 0;
	}
	if(maze[i][j]=='X'){
		return 0;
	}
	int total_path = cntPath(maze,i,j+1,m,n) + cntPath(maze,i+1,j,m,n);
	return total_path;
}

void printAllPath(char maze[][10],int i,int j,int m,int n){
	if(i==m and j==n){
		maze[i][j] = '1';
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<maze[i][j]<<" ";
			}
			cout<<endl;
		}
			maze[i][j] = '0';
			cout<<endl;
			return;
	}
	//Rec Case
	if(i>m or j>n){
		return;
	}
	if(maze[i][j]=='X'){
		return;
	}
	maze[i][j] = '1';
	printAllPath(maze,i,j+1,m,n);
	printAllPath(maze,i+1,j,m,n);
	maze[i][j] = '0'; //backtracking step
	return;
}

int main(){

	char maze[10][10] ={
		"00000",
		"00X0X",
		"000XX",
		"XX000",
		"X0X00",
	};
	if(pathExists(maze,0,0,4,4)){
		cout<<"Mil Gya!";
	}
	else{
		cout<<"Nahi mila!";
	}
	cout<<cntPath(maze,0,0,4,4)<<endl;

	printAllPath(maze,0,0,4,4);

	return 0;
}