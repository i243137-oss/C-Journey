#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool isOperand(char x){
	if(x=='+' || x=='-' || x=='*' || x=='/') return false;
	else return true;
}
int precd(char x){
	if(x=='+' || x=='-') return 1;
	else if( x=='*' || x=='/') return 2;
	else return 0;
}
char * infixToPostfix(char * exp){
	stack<char> st;
	char * postfix=new char[strlen(exp)+1];
	int j=0,i=0;
	while(exp[i]!='\0'){
		if(isOperand(exp[i])) {
			postfix[j++]=exp[i++];
		}else{
			if( st.empty() || precd(exp[i])>precd(st.top())){
				st.push(exp[i++]);
			}else{
				char y=st.top();
				st.pop();
				postfix[j++]=y;
			}
		}
	}
	while(!st.empty()){
		char y=st.top();
		postfix[j++]=y;
		st.pop();
	}
	postfix[j]='\0';
	return postfix;
}
int main(){
    char exp[]="a+b*c-d/e";
    cout<<infixToPostfix(exp);
    return 0;
}