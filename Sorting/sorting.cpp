#include<iostream>
using namespace std;
int main(){
int arr[5]={1,3,17,5,19},temp,count=0;
for(int i=0; i<5; i++){
	for(int j=0;j<4; j++)
	if(arr[j+1]>arr[j]){
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		count++;
	}
	

}
     for(auto val: arr)
     cout<<val;
     cout<<"count "<<count;
}
