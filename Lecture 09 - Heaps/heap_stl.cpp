#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Compare{
public:
	bool operator()(int a,int b){
		return a<b;
	}
};

int main(){

	//priority_queue<int,vector<int>, greater<int> > h;
	priority_queue<int,vector<int>,Compare> h;


	int arr[] = {1,3,2,5,0,8,7};
	int n = sizeof(arr)/sizeof(int);

	for(int i=0;i<n;i++){
		h.push(arr[i]);
	}
	//Pop while not empty
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}

	return 0;
}


