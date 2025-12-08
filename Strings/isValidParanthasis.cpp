#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool isValid(string s){
			stack<char> st;
			for(int i=0; i<s.length(); i++){
				if(s[i]=='[' ||
				   s[i]=='{' ||
				   s[i]=='(' ){
				   	st.push(s[i]);
				   	
				   	
				   }else{
				   	if(st.size()==0) return false; // when close>opem
				   	if(s[i]==']' && st.top()=='[' ||
				   s[i]=='}' && st.top()=='{' ||
				   s[i]==')'&& st.top()=='('){
				   	
				   	st.pop();
				   }else return false;
		
				   
				   
			}}
			return st.size()==0;  // when open>close
			
	
}
int main(){
	string arr="{})";
	cout<<boolalpha<<isValid(arr)<<endl;
return 0;
}
