#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<string,int> f1,pair<string,int> f2){
	return f1.second < f2.second;
}

int main(){

	vector<pair<string,int> > v;
	
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		string fruit;
		int price;
		cin>>fruit>>price;
		v.push_back(make_pair(fruit,price));
	}	
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<" and "<<v[i].second<<endl;
	}

	return 0;


}