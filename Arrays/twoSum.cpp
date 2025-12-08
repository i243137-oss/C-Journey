#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;
pair<int,int> twoSum(vector<int> arr,int target ){
	map<int,int> s;
	int n=arr.size();
	for(int i=0; i<n; i++){
		int first=arr[i];
		int second=target-first;
		if(s.find(second)!=s.end()){
			return {i, s[second]};
		}
		s[first]=i;
	}
	return {-1,-1};
}
pair<int,int> findMissingAndRepeatedValues(vector<vector<int>>& arr){
	int n=arr.size();
	int actualSum=0;
	int expSum=(n*n)*(n*n +1)/2;
	unordered_set<int> s;
	
	int a;
	int b;
	for(int i=0; i<n; i++){
		for(int j=0;j<arr[0].size();j++){
		
		actualSum+=arr[i][j];
		if(s.find(arr[i][j])!=s.end()){
			a=arr[i][j];
		}
		s.insert(arr[i][j]);
	}
		
	}
	 b=expSum-actualSum+a;
	 return {a,b};
}
int main(){
	vector<int> arr={2,7,11,15};
	vector<vector<int>> arr1={{1,2,3},{4,6,7},{8,9,9}};
	int target=9;
	pair<int,int> ans=twoSum(arr,target);
	pair<int,int> ans1=findMissingAndRepeatedValues(arr1);
	cout<<arr[ans.first]<<" and "<<arr[ans.second]<<" makes "<<target<<endl;
	cout<<ans1.first<<" and "<<ans1.second<<" are repeated and missing followingly"<<endl;
return 0;
}
