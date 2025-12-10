// Umair Hassan Class ID3137 SE (C)
#include<iostream>
using namespace std;
int main(){
	char ch;
	int k;
bool flag;
	char arr[4][4];
	cout<<"Welcome to Exam Seating Validator!"<<endl;
	cout<<"=================================="<<endl;
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			cout<<"Row "<<i+1<<" Seat "<<j+1<<" : ";
			do{
				cin>>ch;
				if(ch!='A' && ch!='B' && ch!='C')
				cout<<"Invalid Input"<<endl;
				
			}while(ch!='A' && ch!='B' && ch!='C');
			 arr[i][j]=ch;
		}
		cout<<endl;
	
	}
	cout<<"Current Arrangement : "<<endl;
		for (int i=0; i<4; i++){
				for (int j=0; j<4; j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			
		}
		
		cout<<"Validation Results"<<endl;
		cout<<"=========================="<<endl;
		for (int i=0; i<4; i++){
		
		for (int j=0; j<4; j++)
		
		{
			
			if(arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i+1][j])
			flag=true;
		}

	}
	if(!flag){
		cout<<"Valid Arrangement "<<endl;
	}
	else{
		cout<<"Inalid Arrangement "<<endl;
	}
		
}
