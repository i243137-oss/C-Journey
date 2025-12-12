#include<iostream>
#include<stack>
using namespace std;
int cal(int a , int b, char op){
	switch(op){
		case '+' :
		return	a+b;
			break;
		case '-' :
		return	a-b;
			break;
		case '*' :
		return	a*b;
		case '/' :
		return	a/b;
			break;
	}
	return -1;
}
bool isOperand(char x){
	if(x=='+' || x=='-' || x=='*' || x=='/') return false;
	else return true;
};
int solvePostFix (char * exp){
	stack<int> st;
	int result;
	int a;
	int b;
	for(int i=0; exp[i]!=0; i++){
	if(isOperand(exp[i])){
		st.push(exp[i]-'0');
	}else {
		b=st.top();
		st.pop();
		a=st.top();
		st.pop();
		st.push(cal(a,b,exp[i]));
	}
	}
	result=st.top();
	st.pop();
	return result;
}
int main(){
	char exp[]="231*+9-";
	cout<<solvePostFix(exp);
	return 0;
}
