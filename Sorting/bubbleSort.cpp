#include<iostream>
#include<vector>
using namespace std;
void sortArray(vector<int> &arr){
	int n=arr.size();
	bool isSwap=false;
	for(int i=0; i<n-1;i++){
		for(int j=0; j<n-i-1;j++){
			if(arr[j>arr[j+1]]){
				swap(arr[j],arr[j+1]);
				isSwap=true;
			}
		}
		if(!isSwap){
			return;
		}
	}
}
int main(){
	vector<int> arr={4,3,2,1,0};
	sortArray(arr);
	for(int val: arr){
		cout<<val<<",";
	}
	cout<<endl;
return 0;
}
