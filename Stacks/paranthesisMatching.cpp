#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(char * exp ){
	stack<char> s;
 for (int i=0; exp[i]!='\0'; i++){
 	if(exp[i]=='(' ) s.push(exp[i]);
 	else if( exp[i]==')'){
 		if(s.empty()) return false;
 		s.pop();
	 }
 }
 return s.empty();
 
}
int main(){
	char exp1[] = "((()))()";
	cout<<isBalanced(exp1)<<endl;
}
