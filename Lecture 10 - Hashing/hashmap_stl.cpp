#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;


int main(){
	unordered_map<string,int> m;

	m.insert(make_pair("mango",100));
	m["Apple"] = 200;
	m["Apple"] += 20;
	//Search
	if(m.count("Guava")==0){
		cout<<"Guava not present"<<endl;
	}
	else{
		cout<<m["Guava"]<<endl;
	}
	//Using find function
	unordered_map<string,int>::iterator f = m.find("mango");
	if(f!=m.end()){
		cout<<f->first<<" and "<<f->second<<endl;
	}

	//Extract a element
	cout<<m["Apple"]<<endl;

	//Sare elements 
	m["pineapple"] = 90;
	for(auto p:m){
		cout<<p.first<<" and "<<p.second<<endl;
	}



	return 0;
}
