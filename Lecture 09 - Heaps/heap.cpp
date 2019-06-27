#include<iostream>
#include<vector>
using namespace std;

class Heap{
	vector<int> v;
	bool heapTypeMin;

	bool compare(int a,int b){
		if(heapTypeMin==false){
			return a<b;
		}
		else{
			return a>b;
		}
	}

	void heapify(int idx){

		int left = 2*idx;
		int right = 2*idx+1;

		int last_idx = v.size()-1;
		int mx_idx = idx;

		if(left<=last_idx and compare(v[idx],v[left])){
			mx_idx = left;
		}
		if(right<=last_idx and compare(v[mx_idx],v[right])){
			mx_idx = right;
		}
		if(mx_idx!=idx){
			swap(v[idx],v[mx_idx]);
			heapify(mx_idx);
		}
	}

public:
	Heap(int ds=10,bool ht=true){
		v.reserve(ds);
		v.push_back(-1); //Block the 0th Index
		heapTypeMin = ht;
	}
	//Insert in the Heap (O(LogN))
	void push(int d){
		v.push_back(d);
		int idx = v.size()-1;
		int parent = idx/2;
		while(idx>1 and compare(v[parent],v[idx])){
			swap(v[parent],v[idx]);
			idx = parent;
			parent = parent/2;
		}
	}
	//Get Min/Max
	int getTop(){
		return v[1];
	}
	//Remove Min/Max
	void pop(){
		//Swap first and Last node
		int last = v.size()-1;
		swap(v[1],v[last]);
		//remove the last node
		v.pop_back();
		//Heapify!
		heapify(1);
	}
	bool empty(){
		return v.size()==1;
	}
};


int main(){

	int d;
	cin>>d;

	Heap h;

	while(d!=-1){
		h.push(d);
		cin>>d;
	}

	//Pop 
	while(!h.empty()){
		cout<<h.getTop()<<" ";
		h.pop();
	}

	return 0;
}