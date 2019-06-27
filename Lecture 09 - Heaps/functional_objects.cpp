#include<iostream>
using namespace std;


class Dog{
public:
	bool operator()(int a,int b){
		cout<<"In Dog Operator()";
		cout<<"Comparing "<<a<<" and "<<b<<" ";
		return a<b;
	}
};

int main(){
	Dog funnydog; //Functional Object
	funnydog(1,2); // Functor 
}