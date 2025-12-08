#include<iostream>
#include<string>
using namespace std;
int Calculate_length (string s){
	cout<<"Enter the string\n";
	getline(cin,s);
	int length=0;
	for(int i=0; s[i]!='\0';i++){
		length++;
	}
	cout<<length;
	}
	bool substring (string main, string str){
		int length1,length2;
		cout<<"Enter the main string\n";
		getline(cin,main);
		//i am adnan
		length1=Calculate_length (main);
		cout<<"Enter the string you want to find"<<endl;
		getline(cin,str);
		//adnan
		length2=Calculate_length (str);
		for(int i=0; i<length1; i++){
		}
	}
int main()
{
	string s;
	string main;
	string str;
	Calculate_length(s);
	return 0;
}
