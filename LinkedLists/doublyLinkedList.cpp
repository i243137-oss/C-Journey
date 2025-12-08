#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node *perv;
	Node(int val){
		data=val;
		next=perv=nullptr;
	}
	
};
class DLL{
	Node *head;
	Node *tail;
	public :
		DLL(){
			head=tail=nullptr;
		}
		void push_front(int val){
				Node* newNode=new Node(val);
			if(head==nullptr){
				head=tail=newNode;
			}else{
				newNode->next=head;
				head->perv=newNode;
				
				head=newNode;
			}
		
		}
		void pushBack(int val){
			Node *newNode=new Node(val);
			if(head==nullptr){
				head=tail=newNode;
			}else{
				newNode->perv=tail;
				tail->next=newNode;
				tail=newNode;
				
			
			}
		
		}
		void popFront(){
			Node* temp=head;
			
			head=head->next;
			if(head!=nullptr){
				head->perv=nullptr; // lecture
			}
		
			temp->next=nullptr;
			delete temp;
		}
	void popBack(){
		Node* temp=tail;
		tail=tail->perv;
		if(tail!=nullptr){
			tail->next=nullptr;
		}
	   temp->perv=nullptr;
	   delete temp;
	}
	 
		void printList(){
			Node* temp=head;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main(){
	DLL list;
	
	list.push_front(1);
	
	list.push_front(2);
	list.push_front(3);
	list.pushBack(4);

	list.pushBack(5);
		//list.popBack();
		//list.popFront();
	list.popFront();
	list.printList();
return 0;
}
