#include<iostream>
#include<string>
using namespace std;
bool isAlphaNum(char a) {
    if ((a >= 'a' && a <= 'z') || 
        (a >= 'A' && a <= 'Z') || 
        (a >= '0' && a <= '9'))
        return true;
    else 
        return false;
}

bool isPalindrome(string s){
	int st=0; 
	int end=s.length()-1;
	while(st<end){
		if(!isAlphaNum(s[st])){
			st++;
			continue;
		}
			if(!isAlphaNum(s[end])){
			end--;
			continue;
		}
		if(tolower(s[st])!=tolower(s[end])){
			return false;
		}else{
			st++;
			end--;
		}
		
		
	}
	return true;
}
int main(){
	cout<<isPalindrome("A man ,a plan, a canal :Panama");
return 0;
}
