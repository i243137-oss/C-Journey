#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
void sortColors(vector<int>&arr){
//	sort(arr.begin(),arr.end());
 // BruteFORCE Approach
 int n=arr.size();
 int c1,c2,c3;
  c1=c2=c3=0;
          for(int i=0;i<n;i++){
          	if( arr[i]==0) c1++;
          	else if(arr[i]==1) c2++;
          	else
          	c3++;
		  }
		  int idx=0;
		  for(int i=0; i<c1;i++)   arr[idx++]=0;
		   for(int i=0; i<c2;i++)   arr[idx++]=1;
		    for(int i=0; i<c3;i++)   arr[idx++]=2;
}
*/
//Dutch National Flag Algorithm
void sortColors(vector<int>&arr){
int n=arr.size();
int low=0;
int mid=0;
int high=n-1;
while(mid<=high){

	if(arr[mid]==0){
		swap(arr[low],arr[mid]);
		low++;
		mid++;
	}else if(arr[mid]==1){
	 
	     
		mid++;
		
	}else{
		swap(arr[high],arr[mid]);
		high--;      
	}
}

}
int main(){
	vector<int> arr={2,0,2,1,1,0,1,2,0,0};
	sortColors(arr);
		for(int j:arr){
		cout<<j<<", ";
	}
	cout<<endl;
return 0;
}
