
using namespace std;
#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter any number : ";
	cin>>n;
	for(int i=1; i<=n; i++){
			for(int j=1; j<=n*2-2*i; j++)
			{
				cout<<" ";
			}
			for(int j=i; j>1; j--){
			
			
			cout<<j<<" ";
		}
			for(int j=1; j<=i; j++){
			cout<<j<<" ";
		}
	
		cout<<endl;
	
	}
	cout<<endl<<endl;
		for(int i=1; i<=n; i++){
		for(int j=1; j<=n*2-2*i; j++)
			{
				cout<<" ";
			}
			for(int j=i; j>1; j--){
			
			
			cout<<"/ ";
		}
		cout<<"|";
			for(int j=1; j<i; j++){
			cout<<" \\";
		}
	
		cout<<endl;
	
	}
}
