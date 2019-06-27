#include<iostream>
#include<set>
using namespace std;


int main(){

	set<int,greater<int > > s;
	s.insert(1);
	s.insert(2);
	s.insert(4);
	s.insert(4);
	s.insert(1);
	s.insert(2);

	for(int x:s){
		cout<<x<<" ";
	}

	return 0;
}