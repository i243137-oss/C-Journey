#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
//the logic of sets implementation
using namespace std;
// less Optimized Approach
/*
vector<vector<int>> threeSum(vector<int> &arr){
	int n=arr.size();
	vector<vector<int>> ans;
	set<vector<int>> s;
	for (int i=0; i<n; i++){
		for(int j=i+1; j<n;j++){
			for(int k=j+1; k<n; k++){
		
				if(arr[i]+arr[j]+arr[k]==0){
				
					vector<int> trip={arr[i],arr[j],arr[k]};
					
					sort(trip.begin(),trip.end());
				
				
					if(s.find(trip)==s.end()){
						
						s.insert(trip);
						ans.push_back(trip);
					}
				}
			}
		}
	}
	return ans;
}
*/
// less Better Approach 
/*
vector<vector<int>> threeSum(vector<int> &arr){
	int n=arr.size();

	set<vector<int>> triplet;
	
	for (int i=0; i<n; i++){
		int target =-arr[i];
		set<int> s;
		for(int j=i+1; j<n;j++){
			int a=target-arr[j];
			if(s.find(a)!=s.end()){
				vector<int> trip={a,arr[j],arr[i]};
				sort(trip.begin(),trip.end());
			
				triplet.insert(trip);
				 
			
			}
			s.insert(arr[j]);
			
		
				}
			}
		
		vector<vector<int>> ans(triplet.begin(),triplet.end());
	return ans;
}
*/
// best Approach
vector<vector<int>> threeSum(vector<int> &arr){
	int n=arr.size();
		vector<vector<int>> ans;
		sort(arr.begin(),arr.end());
	


	
	for (int i=0; i<n; i++){
		
		if(i>0 && arr[i]==arr[i-1])continue;
	  int j=i+1;
	  int k=n-1;
	  while(j<k){
	  	int sum=arr[i]+arr[j]+arr[k];
	  	if(sum<0){
	  		j++;
	  	
	  	
	  		
		  }else if(sum>0){
		  	
		  	k--;
		  	
		  }else {
		  	
		  	ans.push_back({arr[i],arr[j],arr[k]});
		  	j++;
		  	k--;
		  	while(j<k && arr[j]==arr[j-1]) j++; 
		  }
	  	
	  }
	}
	return ans;
}
int main(){
	vector<int> arr={-1,0,1,2,-1,-4};
	vector<vector<int>> ans=threeSum(arr);
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[0].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;
}
