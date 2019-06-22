#include<iostream>
using namespace std;

class Node{
public:
	const int data;
	Node*next;
	Node(int d):data(d),next(NULL){}
	~Node(){
		//cout<<"Deleting node "<<data<<" ";
		if(next!=NULL){
			delete next;
		}
		
	}
};

void insertAtHead(Node*&head,int data){
	//pass by reference
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node*n = new Node(data);
	n->next = head;
	head = n;
	return;
}
int length(Node*head){
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}

void insertInMiddle(Node*&head,int d,int p){
	if(p==0){
		insertAtHead(head,d);
		return;
	}
	if(p>length(head)){
		return;
	}
	//otherwise
	Node*t = head;
	for(int jump=1;jump<=p-1;jump++){
		t = t->next;
	}
	Node*n = new Node(d);
	n->next = t->next;
	t->next = n;
	return;
}

void deleteLL(Node*&head){
	delete head;
	head = NULL;
}

int search(Node*head,int key){
	if(head==NULL){
		return -1;
	}
	if(head->data==key){
		return 0;
	}
	int aageKaIndex = search(head->next,key);
	if(aageKaIndex==-1){
		return -1;
	}
	return aageKaIndex+1;
}

Node* recReverse(Node*head){
	if(head==NULL or head->next==NULL){
		return head;
	}
	//rec reverse
	Node* chotaHead = recReverse(head->next);
	/*Node* temp = chotaHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	*/
	//Node *temp = head->next;
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}

void Reverse(Node*&head){
	Node*current = head;
	Node*N = head->next;
	Node* prev = NULL;

	while(current!=NULL){
		N = current->next;
		current->next = prev;
		prev = current;
		current = N;
	}
	head = prev;
}


void deleteInMiddle(Node*&head,int p){
	if(p==0){
		Node*t = head->next;
		head->next = NULL;
		delete head;
		head = t;
		return;
	}
	//middle
	Node *prev=NULL,*temp=head;
	for(int jump=1;jump<=p;jump++){
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
	temp->next = NULL;
	delete temp;
}


void printLL(Node*head){
	//pass by value
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}
Node* mid(Node*l){
	Node* slow = l;
	Node* fast = l->next;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


Node* merge(Node*a,Node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	//rec case
	Node* newhead;
	if(a->data<=b->data){
		newhead = a;
		newhead->next = merge(a->next,b);
	}
	else{
		newhead = b;
		newhead->next = merge(a,b->next);
	}
	return newhead;
}

Node* mergeSort(Node* l){
	//base case
	if(l==NULL or l->next==NULL){
		return l;
	}
	//rec case
	Node* m = mid(l);
	Node*a = l;
	Node* b = m->next;
	m->next = NULL;
	a=mergeSort(a); // a is sorted
	b=mergeSort(b); // b is sorted
	return merge(a,b); 
}



int main(){
	Node*head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,0);
	insertAtHead(head,5);
	insertAtHead(head,3);
	printLL(head);
	insertInMiddle(head,4,2);
	printLL(head);
	//deleteInMiddle(head,1);
	printLL(head);
	head = recReverse(head);
	printLL(head);

	//cout<<"Index of search 4 - "<<search(head,4)<<endl;
	head = mergeSort(head);
	printLL(head);
	//deleteLL(head);


	return 0;
}