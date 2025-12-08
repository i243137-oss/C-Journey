//Umair Hassan Class ID 3137 Assignment 2 SE(C)
#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";                      //for number
    cin >> n;
    cout<<endl<<endl;
    	for(int i=1; i<=n; i++){                              //rows
		for(int j=1; j<=n*2-2*i; j++)                        // columns
			{
				cout<<" ";
			}
			for(int j=i; j>1; j--){
			
			
			cout<<"\\ ";
		}
		cout<<"|";
			for(int j=1; j<i; j++){
			cout<<" /";
		}
	
		cout<<endl;
	
	}

    
}

