#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int val){
			data=val;
			next=nullptr;
		}
};
class CircularList{
	Node *head;
	Node *tail;
	public:
	CircularList(){
		head=tail=nullptr;
		
	}
	void insertAtHead(int val){
		Node *newNode=new Node(val);
		if(head==nullptr){
			head=tail=newNode;
			tail->next=newNode;
		}
		else{
			newNode->next=head;
			head=newNode;
			tail->next=head;
		}
	}
	void insertAtTail(int val){
			Node *newNode=new Node(val);
		if(head==nullptr){
			head=tail=newNode;
			tail->next=newNode;
		}
		else{
			newNode->next=head;
			tail->next=newNode;
		    tail=newNode;
		}
		
	}
	void deleteAtHead(){
		if(head==nullptr) {
			return;
		}else if(head==tail){
			delete head;
			head=tail=nullptr;
		}else{
		
		Node *temp=head;
		head=head->next;
		tail->next=head;
		temp->next=nullptr;
		delete temp;
	}
	}
	void printList(){
		Node *temp=head->next;
		cout<<head->data<<" ";
		while(temp!=head){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<head->data;
		cout<<endl;
	}
	};
int main(){
	CircularList list;
	list.insertAtHead(4);
	list.insertAtHead(8);
///	list.insertAtTail(9);
	list.insertAtHead(7);
	list.deleteAtHead();
	list.printList();
return 0;
}
