#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
int data;
Node* left;
Node * right;
Node(int val){
	data=val;
	left=right=nullptr;
}	
};
static int idx=-1;
Node * binaryList(vector<int>inOrder){
	idx++;
	if(inOrder[idx]==-1) return nullptr;
	Node * root=new Node(inOrder[idx]);
	root->left=binaryList(inOrder);
	root->right=binaryList(inOrder);
	return root;
}
void preOrder(Node * root){
	if(root==nullptr){
		return;
	}
		cout<<root->data<<" ";
	preOrder(root->left);

	preOrder(root->right);
}
void inOrder(Node * root){
	if(root==nullptr){
		return;
	}
		
	inOrder(root->left);
cout<<root->data<<" ";
	inOrder(root->right);
}
void postOrder(Node * root){
	if(root==nullptr){
		return;
	}
		
	postOrder(root->left);

	postOrder(root->right);
	cout<<root->data<<" ";
}
void orderLevelTrav(Node* root){
	queue<Node *> q;
	q.push(root);
	while(q.size()>0){
		Node * curr=q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left!=nullptr) q.push(curr->left);
		if(curr->right!=nullptr) q.push(curr->right);
	}
}
int height(Node *root){
	if(root==nullptr) return 0;
	int left=height(root->left);
	int right=height(root->right);
	return max(right,left)+1;
}
int count (Node * root ){
	if(root==nullptr){
		return 0;
	}
	int left=count(root->left);
	int right=count(root->right);
	return left+right+1;
}
int main(){
	vector<int> preOrde={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
	Node* a=binaryList(preOrde);
	preOrder(a);
	cout<<endl;
	inOrder(a);
	cout<<endl;
	postOrder(a);
	cout<<endl;
	orderLevelTrav(a);
	cout<<endl<<height(a)<<endl;;
	cout<<count(a)<<endl;
	
return 0;
}
