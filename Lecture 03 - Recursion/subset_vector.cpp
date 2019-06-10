#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

void generate_subset(char *input,char *output,int i,int j,vector<string> &s){
	if(input[i]=='\0'){
		output[j] ='\0';
		//cout<<output<<" ";
		string temp(output);
		s.push_back(temp);
		return;
	}
	//rec case
	output[j] = input[i];
	generate_subset(input,output,i+1,j+1,s);
	//output[j] = '\0';
	generate_subset(input,output,i+1,j,s);

}
bool compare(string a,string b){
    if(a.length()==b.length()){
        return a<b;
    }
    return a.length()<b.length();
}

int main(){

	char input[10],output[10];
	cin>>input;
	vector<string> s;
	generate_subset(input,output,0,0,s);

	sort(s.begin(),s.end(),compare);

	//print the set
	for(string x:s){ //for each loop
		cout<<x<<",";
	}


	return 0;
}