#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




class Triplet{
public:
	string name;
	int x,y;
	Triplet(string name,int x,int y){
		this->name = n;
		this->x = x;
		this->y = y;
	}

};
bool compare(Triplet a,Triplet b){
	return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
}

int main(){
	int n;
	cin>>n;
	vector<Triplet> v;
	for(int i=0;i<n;i++){
		string name;
		int x,y;
		cin>>name>>x>>y;
		Triplet t(name,x,y);
		v.push_back(t);
	}

	sort(v.begin(),v.end(),compare);

	for(Triplet t:v){
		cout<<t.name<<" "<<t.x*t.x+t.y*t.y<<endl;
	}

	return 0;
};
