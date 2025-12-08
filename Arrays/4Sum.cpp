#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;
vector<vector<int>> fourSum(vector<int> arr){
	int n=arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n; i++){
		if(arr[i]==arr[i-1]&& i>0) continue;
		for(int j=i+1;; j<n){
			int p=j+1;
			int q=n-1;
			while(p<q){
				
				long long sum=(long long)arr[i]+(long long)arr[j]+(long long)arr[p]+(long long)arr[q];
				if(sum<0) p++;
				else if(sum>0)q--;
				else {
					
					ans.push_back({arr[i],arr[j],arr[q],arr[p]});
					p++;
					q--;
						while(arr[p]==arr[p-1]&&p<q) p++;
					
				}
			}
			j++;
			while(arr[j]==arr[j-1]&&j<n) j++;
		}
	}
	return ans;
}
int main(){
	vector<int> arr={-2,-1,-1,1,1,2,2};
	vector<vector<int>> ans;//=fourSum(arr);
	string a="1235ynfmf.'";
	string b=alnum(a);
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[0].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;
}
