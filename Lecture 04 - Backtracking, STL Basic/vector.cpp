#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	return a>b;
}

int main(){
	vector<int> v;
	v.reserve(100);
	for(int i=0;i<=5;i++){
		v.push_back(i*i); //insert at end
	}

	//Print
	v.pop_back();
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "; //read or update 
	}

	sort(v.begin(),v.end(),compare);

	cout<<endl<<v.capacity()<<endl;
	cout<<v.max_size()<<endl;

	return 0;
}