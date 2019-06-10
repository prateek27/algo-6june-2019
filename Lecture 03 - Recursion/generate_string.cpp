#include<iostream>
using namespace std;

void generateString(char input[],char output[],int i,int j){
	//base case
	if(input[i]=='\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	//include one
	int digit = input[i]-'0';
	char ch = digit + 'A' - 1;
	output[j] = ch;
	generateString(input,output,i+1,j+1);
	//include two
	if(input[i+1]!='\0'){
		int secondDigit = input[i+1] - '0';
		int no = 10*digit + secondDigit;
		if(no<=26){
			output[j] = no + 'A' - 1;
			generateString(input,output,i+2,j+1);
		}
	}
	return;
}

int main(){
	char input[100];
	cin>>input;
	char output[100];
	generateString(input,output,0,0);

	return 0;
}