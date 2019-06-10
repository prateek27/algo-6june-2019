#include<iostream>
#include<set>
#include<cstring>
using namespace std;

void generate_subset(char *input,char *output,int i,int j,set<string> &s){
	if(input[i]=='\0'){
		output[j] ='\0';
		//cout<<output<<" ";
		string temp(output);
		s.insert(temp);
		return;
	}
	//rec case
	output[j] = input[i];
	generate_subset(input,output,i+1,j+1,s);
	//output[j] = '\0';
	generate_subset(input,output,i+1,j,s);

}

int main(){

	char input[10],output[10];
	cin>>input;
	set<string> s;
	generate_subset(input,output,0,0,s);

	//print the set
	for(string x:s){ //for each loop
		cout<<x<<",";
	}





	return 0;
}