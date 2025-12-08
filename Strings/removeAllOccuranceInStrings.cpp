#include<iostream>
#include<vector>
using namespace std;
void removeOccurance(string &s,string part){
	while(s.length()>=0 && s.find(part)<=s.length()){
		s.erase(s.find(part),part.length());
	}
}
int main(){
	string s="abcabcabca";
	string part ="abc";
	removeOccurance(s,part);
	cout<<s<<endl;
return 0;
}
