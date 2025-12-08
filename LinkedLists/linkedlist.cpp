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
class List{
	Node* head;
	Node *tail;
	public:
		List(){
			head=nullptr;
			tail=nullptr;
			
		}
		void pushFront(int val){
			Node* newNode=new Node(val);
			if(head==nullptr){
				head=tail=newNode;
			return;
			} else{
				newNode->next=head;
				head=newNode;
				return ;
			}
		}
		void pushBack(int val){
			Node *newNode= new Node( val);
			if(head==nullptr){
				head=tail=newNode;
			}else{
			
			
			tail->next=newNode;
			tail=newNode;
		}
		}
		void popFront(){
			if(head==nullptr){
				return;
			}else{
			
			
			Node *temp=head;
			head=temp->next;
			temp->next=nullptr;
			delete temp;
		}
		}
		void popBack(){
			if(head==nullptr){
				return;
			}
			Node *temp=head;
			while(temp->next!=tail){
			    temp=temp->next;                        //else we can writr temp->next->next
		}
		temp->next=nullptr;
		delete tail;
		tail=temp;
	}
	void insertMiddle(int val, int pos){
		if(pos<0) {
			return;
		}
		if(pos==0){
			pushFront(val);
			return;
		}
		Node *temp=head;
		Node *newNode= new Node(val);
		for(int i=0; i<pos-1; i++){
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
		void printList(){
			Node *temp=head;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
					temp=temp->next;
			}
		
			cout<<endl;
			
		}
};
int main(){
	List li;
	li.pushFront(2);
	li.pushFront(3);
	li.pushFront(2);
	li.pushBack(7);
	
	
	li.insertMiddle(30,1);
	li.printList();
	
	
}