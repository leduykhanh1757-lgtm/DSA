#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

node *makeNode(int x){
	node *newNode = new node;
	newNode -> data = x;
	newNode -> next = NULL;
	return newNode;
}

void duyet(node *head){
	while(head != NULL){
		cout<<head -> data<<" ";
		head = head -> next;
	}
	cout<<endl;
}

int sz (node *head){
	int dem = 0;
	while(head != NULL){
		++dem;
		head = head -> next;
	}
	return dem;
}

void themDau (node *&head,int x){
	node *newNode = makeNode(x);
	newNode -> next = head;
	if(head != NULL){
		head -> prev = newNode;
	}
	head = newNode;
}

void themCuoi (node *&head,int x){
	node *newNode = makeNode(x);
	node *tmp = head;
	if(tmp == NULL){
		newNode -> next = head; 
		if(head != NULL) head->prev = newNode;
		head = newNode;
		return;
	}
	while(tmp -> next != NULL){
		tmp = tmp -> next;
	}
	tmp -> next = newNode;
	newNode -> prev = tmp;
}

void themGiua (node *&head,int x,int k){
	if(k<1||k>sz(head)+1) return;
	node *tmp = head;
	node *newNode = makeNode(x);
	if(k==1){
		newNode -> next = head;
		if(head !=NULL) head->prev = newNode;
		head = newNode;
		return;
	}
	for(int i=1;i<=k-1;i++){
		tmp = tmp -> next;
	}
	//tmp : k
	newNode -> next = tmp;
	// k-1 => newNode
	tmp->prev->next = newNode;
	newNode -> prev = tmp -> prev;
	tmp -> prev = newNode;
}

void xoaDau (node *&head){
	if(head == NULL) return;
	node *xoa = head;
	head = head -> next;
	if(head != NULL){
		head -> prev = NULL;
	}
	delete xoa;
}

void xoaCuoi (node *&head){
	if(head == NULL) return;
	node *tmp = head;
	if(tmp -> next ==NULL){
		head = NULL; delete tmp;
		return;
	}
	while(tmp->next->next != NULL){
		tmp = tmp -> next;
	}
	node *xoa = tmp -> next;
	tmp -> next = NULL;
	delete xoa;
}


void xoaGiua (node *&head,int k){
	if(k<1||k>sz(head)) return;
	node *tmp = head;
	if(k==1){
		head = head -> next;
		if(head!=NULL) head -> prev =NULL;
		delete tmp; return;
	}
	for(int i=1;i<=k-1;i++){
		tmp = tmp -> next;
	}
	//tmp:k
	tmp -> prev -> next = tmp -> next;
	tmp -> next -> prev = tmp -> prev;
	delete tmp;
	
}

int main(){
	node *head = NULL;
	for(int i=1;i<=10;i++){
		themCuoi(head,i);
	}
	xoaCuoi(head);
	duyet(head);
}