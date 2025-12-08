#include<iostream>
#include<vector>
using namespace std;
vector<int> productOfArray(vector<int> & arr){
	int n=arr.size();
	vector<int> ans;
	for(int i=0; i<n;i++){
		          int answer=1;
		for(int j=0; j<n; j++){
			if(i!=j){
				answer*=arr[j];
				
			}
		}
		ans.push_back(answer);
	}
	return ans;
}
int main(){
	vector<int> arr={1,2,3,4};
	vector<int>ans=productOfArray(arr);
	for(int val: ans){
		cout<<val<<" ";
	}
	cout<<endl;
return 0;
}
