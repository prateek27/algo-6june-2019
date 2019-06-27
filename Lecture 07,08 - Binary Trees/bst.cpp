#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
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

void root2Leaf(Node*root,vector<int> &v){
	if(root==NULL){
		return;
	}
	if(root->left==NULL and root->right==NULL){
		v.push_back(root->data);
		//print the vector
		for(int x:v){
			cout<<x<<"->";
		}
		cout<<endl;
		v.pop_back();
		return;
	}
	//Rec Case
	v.push_back(root->data);
	root2Leaf(root->left,v);
	root2Leaf(root->right,v);
	v.pop_back();
	return;


}

void mirror(Node*root){

	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
	return;
}

Node* insertInBST(Node*root,int d){
	if(root==NULL){
		Node* n = new Node(d);
		return n;
	}
	//Insert in the left subtree 
	if(d<root->data){
		root->left = insertInBST(root->left,d);
	}
	else{
		root->right = insertInBST(root->right,d);
	}
	return root;
}

Node* takeInput(){
	int d;
	cin>>d;
	Node*root = NULL;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}

bool search(Node*root,int key){
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(key<root->data){
		return search(root->left,key);
	}
	return search(root->right,key);
}

Node* deleteANode(Node*root,int key){
	//base case
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		//delete this node
		//3 Cases -> Leaf Node, Single Child, Double Children
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left!=NULL and root->right==NULL){
			Node*temp = root->left;
			delete root;
			return temp;
		}
		else if(root->right!=NULL and root->left==NULL){
			Node*temp = root->right;
			delete root;
			return temp;
		}
		else{
			Node*temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = deleteANode(root->right,root->data);
			return root;
		}
	}
	else if(root->data>key){
		root->left = deleteANode(root->left,key);
		return root;
	}
	else{
		root->right = deleteANode(root->right,key);
		return root;
	}
}

Node* arrayToBST(int arr[],int s,int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	Node*root = new  Node(arr[mid]);
	root->left = arrayToBST(arr,s,mid-1);
	root->right = arrayToBST(arr,mid+1,e);
	return root;
}

class LLPair{
public:
	Node*head;
	Node*tail;
};

LLPair tree2LL(Node*root){
	//base case
	LLPair l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	//Rec Case
	if(root->left!=NULL and root->right==NULL){
		LLPair LeftLL = tree2LL(root->left);
		LeftLL.tail ->right = root;
		l.head = LeftLL.head;
		l.tail = root;
		return l;
	}
	else if(root->right!=NULL and root->left==NULL){
		LLPair rightLL = tree2LL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	else{
		LLPair LeftLL = tree2LL(root->left);
		LLPair rightLL = tree2LL(root->right);
		LeftLL.tail ->right = root;
		root->right = rightLL.head;
		l.head = LeftLL.head;
		l.tail = rightLL.tail;
		return l;
	}	
}

Node* preToBST(int *pre,int *in,int s,int e){
	static int x = 0;
	if(s>e){
		return NULL;
	}
	Node*root = new Node(pre[x]);
	//search the index of x in preorder
	int j;
	for(j=s;j<=e;j++){
		if(in[j]==pre[x]){
			break;
		}
	}
	x++;
	//j-->index of pre[x] in inorder
	root->left = preToBST(pre,in,s,j-1);
	root->right  = preToBST(pre,in,j+1,e);
	return root;

}

int countBST(int n){
	if(n==0){
		return 1;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += countBST(i-1)*countBST(n-i);
	}
	return ans;
}




int main(){

	//Node* root = buildTree();
	int pre_arr[] = {7,3,1,5,10,9,11};
	int in_arr[] = {1,3,5,7,9,10,11};
	int n = sizeof(in_arr)/sizeof(int);

	//Node*root = preToBST(pre_arr,in_arr,0,n-1);//arrayToBST(arr,0,n-1);
	//levelOrder(root);

	cout<<countBST(3)<<endl;
	
	/*
	Node* root = takeInput();
	levelOrder(root);

	int d;
	root = deleteANode(root,8);
	root = deleteANode(root,15);
	root = deleteANode(root,10);

	levelOrder(root);
	
	LLPair l = tree2LL(root);
	Node* temp = l.head();

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->right;
	}
	*/


	return 0;
}