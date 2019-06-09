#include<iostream>
#include<cstring>
using namespace std;

void filterChars(char *input,int i){

	int temp = i;
	int j = 0;
	while(temp>0){
		int last_bit = temp&1;
		if(last_bit){
			cout<<input[j];
		}
		j++;
		temp = temp>>1;
	}
	cout<<endl;
	return;
}

void printSubsets(char *input){

	int n = strlen(input);
	for(int i=0;i<(1<<n);i++){
		filterChars(input,i);
	}

}

int main(){

	char input[100];
	cin>>input;
    printSubsets(input);


	return 0;
}