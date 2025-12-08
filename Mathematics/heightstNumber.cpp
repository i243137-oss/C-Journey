#include<iostream>
using namespace std;
int main(){
	int arr[4]={1,2,3,9};
	int arr2[4]={1,2,3,9};
	bool flag=true;
	int h=arr[0];
	for(int i=0; i<4 && flag; i++){
		if(arr[i]!=arr2[i])
		flag=false;
	}
	if(flag)
	cout<<"Yes";
	else 
		cout<<"No";
	
}
