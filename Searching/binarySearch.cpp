#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarySearch(vector<int> vec,int target){
	int n=vec.size();
	int st=0;
	int end=n-1;
	while(st<=end){
	
	//	int mid=(st+end)/2;   It can cause overflow
	int mid=st+(end-st)/2;
		if(target<vec[mid]){
			end=mid-1;
		}else if(target>vec[mid]){
			st=mid+1;
		}else if(target==vec[mid]){
			return mid;
		}
		}
		return -1;
		
	
}
int binarySearch(vector<int> vec, int target,int st,int end){
	if(st<=end){
		int mid=st+(end -st)/2;
		if(target<vec[mid]){
			return binarySearch(vec,target,st,mid-1);
		}else if(target>vec[mid])
			return binarySearch(vec,target,mid+1,end);
		else 
		return mid;
	}else{
		return -1;
	}
}
int main(){
	vector <int> vec={-1,0,3,5,9,12};
	int target=12;
cout<<binarySearch(vec,target)<<endl;
cout<<binarySearch(vec,target,0,5)<<endl;

return 0;
}
