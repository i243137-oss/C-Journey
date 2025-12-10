//Umair Hassan Class ID3137 SE (C)
#include<iostream>
using namespace std;
int main(){
	int num;
	int arr[4][4];
	bool flag=true;
	int counter=0;
	
cout<<"Welcome to Mini Sudoku Validator! "<<endl;
cout<<"=================================="<<endl;
cout<<"Enter numbers for the 4x4 grid (1-4 only): "<<endl;
for(int i=0; i<4; i++){
	
	for(int j=0; j<4; j++){
		do{
				cout<<"Row "<<i+1<<" Number "<<j+1<<" : ";
			cin>>num;
			if(num<1 || num>4)
			cout<<"Invalid Input"<<endl;
		}while(num<1 ||num>4);
		arr[i][j]=num;
		cout<<endl;
		
	}
}
cout<<"Current Grid "<<endl;
	for (int i=0; i<4; i++){
	
		int arr2[4]={0,0,0,0};
				for (int j=0; j<4; j++){
					cout<<arr[i][j]<<" ";
					
						arr2[j]=arr[i][j];
					
						}
						
			
			
				
				cout<<endl;
			
		}
		
	if(!flag)
	cout<<"Valid Input "<<endl;	
}
