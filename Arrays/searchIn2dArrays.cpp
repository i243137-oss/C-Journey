#include<iostream>
#include<vector>
using namespace std;
bool binarySearch(vector<vector<int>> & arr,int target){
	int mid=0;
	int m=arr.size();
	int n=arr[0].size();
	int stRow=0;
	int endRow=m-1;
	while(stRow<=endRow){
		int midRow=stRow+(endRow-stRow)/2;
		if(target>=arr[midRow][0] && target<=arr[midRow][n-1]){
			int st=0; 
			int end=n-1;
			while(st<=end){
				int mid=st+(end-st)/2;
				if(target==arr[midRow][mid]){
					return true;
				}else if(target<arr[midRow][mid]){
					end=mid-1;
				}else{
					st=mid+1;
				}
				
			    
			}
		}
		else if(target<arr[midRow][0]){
			endRow=midRow-1;
		}else {
			stRow=midRow+1;
		}
	}
	
	return false;

	
}
bool search(vector<vector<int>> arr,int target){
	int m=arr.size();
	int n=arr[0].size();
	int row=0; 
	int col=n-1;
	while(row<m && col>=0){
		if(target==arr[row][col]){
			return true;
		}else if(target<arr[row][col]){
			col--;
		}else{
			row++;
		}
	}
	return false;
}
int main(){
	vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> arr1={ 
	{1,4,7,11,15},
	{2,5,8,12,19},
	{3,6,9,16,22},
	{10,13,14,17,24},
	{18,21,23,26,30}
	};
	
	
	
	
	
	
	cout<<boolalpha<<binarySearch(arr,9)<<endl;
	cout<<boolalpha<<search(arr1,34)<<endl;
return 0;
}
