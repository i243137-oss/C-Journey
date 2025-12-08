#include<iostream>
using namespace std;
int main(){
	string word;
	int i,j;
	cout<<"Enter word in lowercase :"<<endl;
	cin>>word;
	i=word.length();
	j=0;
	while(j<=i){
		word[j]-=32;
		j++;
	}
	cout<<word;
	


	return 0;
}
