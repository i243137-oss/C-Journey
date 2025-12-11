#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* left;
		Node * right;
	Node (int data){
		this->data=data;
		left=right=nullptr;
		
	}
};
 void insertData(Node * & root, int data){
 	if(root==nullptr){
 		root=new Node(data);
 		
	 }else if(root->data==data ){
	 	return;
	 }else if(data<root->data){
	 	
	 	insertData(root->left,data);
	 }else{
	 	insertData(root->right,data);
	 	
	 }
 }
 Node * search(Node * root, int key){
 	if(root==nullptr){
 		return nullptr;
	 }else if(root->data==key){
	 	return root;
	 }else if(root->data>key){
	 	return search(root->left,key);
	 	
	 }
	 else return search(root->right,key);
 }
 void printInOrder(Node * root){
 	if(root==nullptr) return;
 	printInOrder(root->left);
 	
 	cout<<root->data<<", ";
 	printInOrder(root->right);
 }
    int main(){
    	Node * root=new Node(10);
    	insertData(root,5);
    	insertData(root,15);
    	insertData(root,3);
    	insertData(root,7);
    	insertData(root,12);
    	insertData(root,18);
    	printInOrder (root);
    	cout<<endl;
    	cout<<(search(root,7) ? "Key Found ": "Not Found")<<endl;
    	return 0;
    }