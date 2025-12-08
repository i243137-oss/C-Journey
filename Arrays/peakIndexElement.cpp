#include<iostream>
#include<vector>
using namespace std;
int peakIndexElement(vector<int> &arr){
	int n=arr.size();
	int st=2;
	int end=n-2;
	while(st<=end){
		int mid=st+(end-st)/2;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
			return mid;
		}else if (arr[mid]>arr[mid-1]){
			st=mid+1;
		}else{
			end=mid-1;
		}
	}
	return -1;
	
}
using namespace std;
int main(){
	vector<int> arr={0,3,8,9,5,4};
	cout<<"Peak Element "<<arr[(peakIndexElement(arr))]<<endl;
return 0;
}
