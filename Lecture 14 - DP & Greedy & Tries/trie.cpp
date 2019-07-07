#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;
public:
	Node(char d){
		data = d;
		isTerminal = false;
	}
};

class Trie{
	Node* root;
public:
	Trie(){
		root = new Node('\0');
	}
	void addWord(char word[]){

		Node*temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->m.count(ch)==0){
				Node* n = new Node(ch);
				temp->m[ch] = n;
				temp = n;
			}
			else{
				temp = temp->m[ch];
			}
		}
		temp->isTerminal  = true;
	}
	bool searchWord(char word[]){
		Node*temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->m.count(ch)==0){
				return false;
			}
			else{
				temp = temp->m[ch];
			}
		}
		return temp->isTerminal;
	}
};



int main(){

	Trie t;
	char words[][10] = {"apple","ape","not","news"};
	for(int i=0;i<4;i++){
		t.addWord(words[i]);
	}
	char w[10];
	cin>>w;
	if(t.searchWord(w)){
		cout<<w<<" found!";
	}
	else{
		cout<<"coulnt find!";
	}


	return 0;
}