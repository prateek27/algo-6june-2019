#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


bool compare(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}
	return a.length()<b.length();
}


int main(){
	int n;
	cin>>n;
	set<string> v;
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		v.insert(name);
	}

	for(string t:v){
		cout<<t<<" ";
	}	

	return 0;
};
