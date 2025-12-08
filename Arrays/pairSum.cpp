#include<iostream>
#include<vector>

using namespace std;
// BruteForce Approach
/*
vector<int> pairSum(vector<int>& num, int target){
	vector <int> ans;
	int n=num.size();
	for(int i=0; i<n; i++){
		for(int j=i+1;j<n;j++){
			if(num[i]+num[j]==target){
				ans.push_back(i);
				ans.push_back(j);
				return ans;
				
				
			}
		}
	}
	return ans;
}
*/
//Optimal Approach
vector<int> pairSum(vector<int>& num, int target){
	vector <int> ans;
	int n=num.size();
	int i=0 , j=n-1;
	
	while(i<j){
			int pairSum=num[i]+num[j];
		if(pairSum>target)
		j--;
		else if(pairSum<target)
		i++;
		else {
				ans.push_back(i);
				ans.push_back(j);
				return ans;
		}
	}

	return ans;
}

int main(){
	vector<int> vec={2,7,11,15};
	int target=26;
	vector <int> ans=pairSum(vec,target);
	cout<<ans[0]<<","<<ans[1]<<endl;
return 0;
}
