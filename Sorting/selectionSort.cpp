#include<iostream>
#include<vector>
using namespace std;
void sortArray(vector<int> &arr){
	int n=arr.size();
	for(int i=0;i<n-1;i++){
		int smallestIdx=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[smallestIdx]){
				smallestIdx=j;
			}
		
			
	}
		swap(arr[i],arr[smallestIdx]);
}
}
int main(){
	vector<int> arr={4,2,1,0,3};
	sortArray(arr);
	for(int j:arr){
		cout<<j<<", ";
	}
	cout<<endl;
	
	
return 0;
}
