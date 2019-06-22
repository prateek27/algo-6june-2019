#include<iostream>
#include<queue>
#include<cmath>
using namespace std;


// Binary Tree!
class Node{
public:
	int data;
	Node*left;
	Node*right;
public:
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}
	Node*root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
//PreOrder Print
void printTree(Node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}
void printIn(Node*root){
	if(root==NULL){
		return;
	}

	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}
void printPost(Node*root){
	if(root==NULL){
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
	
}
void printAtLevelK(Node*root,int k){
	//base case
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);

}

int height(Node*root){
	//return root==NULL?0: 1+max(height(root->left),height(root->right));
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2)+1;
}

void printAllLevels(Node*root){
	int levels = height(root);

	for(int k=0;k<=levels;k++){
		printAtLevelK(root,k);
		cout<<endl;
	}
}

int cntNodes(Node*root){
	if(root==NULL){
		return 0;
	}
	return 1+cntNodes(root->left) + cntNodes(root->right);
}

int replaceNodesBySum(Node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left == NULL and root->right==NULL){
		return root->data;
	}
	int temp = root->data;
	root->data = replaceNodesBySum(root->left) + replaceNodesBySum(root->right);
	return root->data + temp;
}

//Level Order Print
void levelOrder(Node*root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* f = q.front();
		if(f==NULL){
			q.pop();
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();

			cout<<f->data<<" ";
			if(f->left!=NULL){
				q.push(f->left);
			}
			if(f->right!=NULL){
				q.push(f->right);
			}
		}
	}
}

Node* levelOrderBuild( ){
	queue<Node*> q;
	int d;
	cin>>d;

	Node*root = new Node(d);
	q.push(root);

	while(!q.empty()){
		int c1,c2;
		cin>>c1>>c2;
		Node*f = q.front();
		q.pop();

		if(c1!=-1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}
	return root;
}

int diameter(Node*root){
	//base case
	if(root==NULL){
		return 0;
	}
	//rec case
	int op1 = height(root->left) + height(root->right);
	int op2 = max(diameter(root->left),diameter(root->right));
	return max(op1,op2);
}

class MyPair{
public:
	int height;
	int diameter;
};

MyPair diameteroptimisied(Node*root){
	//base case
	MyPair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}
	//rec case 
	MyPair left = diameteroptimisied(root->left);
	MyPair right = diameteroptimisied(root->right);

	p.height = max(left.height,right.height) + 1;
	p.diameter = max(max(left.diameter,right.diameter),left.height+right.height);
	return p;
}

class HBPair{
public:

	int height;
	bool balance;
};

HBPair isHeightBalanced(Node*root){
	//Base Case
	HBPair p;
	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}
	//Rec
	HBPair left = isHeightBalanced(root->left);
	HBPair right = isHeightBalanced(root->right);

	if(abs(left.height-right.height)<=1 and left.balance and right.balance){
		p.balance = true;
	}
	else{
		p.balance = false;
	}
	p.height = max(left.height,right.height)+1;
	return p;
}

class PairIE{
public:
	int inc;
	int exc;
};

PairIE maxSum(Node*root){
	//Base Case
	PairIE p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}
	//rec case
	PairIE L,R;
	L = maxSum(root->left);
	R = maxSum(root->right);

	p.inc = root->data + L.exc + R.exc;
	p.exc = max(L.inc,L.exc) + max(R.inc,R.exc);
	return p;
}



int main(){

	//Node* root = buildTree();
	Node* root = levelOrderBuild();
	printTree(root);
	cout<<endl;
	//printAtLevelK(root,2);
	//replaceNodesBySum(root);
	//printAllLevels(root);
	levelOrder(root);
	if(isHeightBalanced(root).balance){
		cout<<"Yes HB!";
	}
	else{
		cout<<"No!";
	}
	PairIE p = maxSum(root);
	cout<<max(p.inc,p.exc)<<endl;

	return 0;
}