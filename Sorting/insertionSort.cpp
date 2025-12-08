#include<iostream>
#include<vector>
using namespace std;
void sortArray(vector<int> &arr){
	int n=arr.size();
	for(int i=1;i<n;i++){
	int current=arr[i];
	int perv=i-1;
		while(perv>=0 && arr[perv]>current){
			arr[perv+1]=arr[perv];
			perv--;
		}	
		arr[perv+1]=current;
	
	
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
