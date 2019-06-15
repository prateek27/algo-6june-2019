#include<iostream>
using namespace std;

void permute(char *input,int i){
	//base case
	if(input[i]=='\0'){
		cout<<input<<endl;
		return ;
	}
	//rec case 
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		permute(input,i+1);
		swap(input[i],input[j]);
	}

}

int main(){

	char input[10];
	cin>>input;
	permute(input,0);
	

	return 0;
}