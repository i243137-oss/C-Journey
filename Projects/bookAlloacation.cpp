#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> &arr,int book,int std,int Max){
	int stu=1;
	int pages=0;
	for(int i=0;i<book;i++){
		if(arr[i]>Max) return false;
		if(pages+arr[i]<=Max){
			pages+=arr[i];
			
		}else{
			stu++;
			pages=arr[i];
		}
	}
	return stu>std ? false : true;
}
int bookAllocate(vector<int> &arr,int book,int std){
	int sum=0;
	for(int val: arr){
		sum+=val;
	}
	int st=0;
	int end=sum;
	int ans=-1;
	while(st<=end){
		int mid= st+(end-st)/2;
		if(isValid(arr,book,std,mid)){
			ans=mid;
			end=mid-1;
			
		}
	else{
		st=mid+1;
	}

}
	return ans;
	}
int main(){
	vector<int> arr={2,1,3,4};
	int std=2;
	int book=4;
	cout<<"Max Books "<<bookAllocate(arr,book,std)<<endl;
return 0;
}
