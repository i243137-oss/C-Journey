#include<iostream>
#include<vector>
using namespace std;
int singleElement(vector<int> &arr){
	int n=arr.size();
	if(arr[0]!=arr[1]){
		return 0;
	}
	if(arr[n-1]!=arr[n-2]){
		return n-1;
	}
	if(n==1){
		return 0;
	}
	int st=1;
	int end=n-2;
	while(st<=end){
	int 	mid=st+(end-st)/2;
		if(arr[mid]!=arr[mid+1]&& arr[mid]!=arr[mid-1]){
			return mid;
		}else {
			if(mid%2==0){
				if(arr[mid]==arr[mid-1]){
					end=mid-1;
				}else{
					st=mid+1;
				}
				
			}else{
				if(arr[mid]==arr[mid-1]){
				st=mid+1;
				}else{
					end=mid-1;
				}
			}
		}
	}
	return -1;
}

int main(){
	vector<int> arr={1,1,2,2,3,4,4};
	cout<<"Single Element "<<arr[singleElement(arr)]<<endl;
return 0;
}
