#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n=7;
	vector <int> vec={3,-4,5,4,-1,7,-8};
	
	int maxSum=INT_MIN;
	// Brute Force Approach
	/*
		for(int st=0; st<n; st++){
		int currentSum=0;
		for(int end=st; end<n; end++){
			currentSum+=vec[end];
			maxSum=max(currentSum,maxSum);
		
		}
	
	}
	*/
	// Kadane Algorithems
	int currentSum=0;
	for(int val : vec){
		currentSum+=val;
		maxSum=max(currentSum,maxSum);
		if(currentSum<0){
		
		
		
		currentSum=0;
	}
		
	}
	cout<<"Max Array Sum : "<<maxSum<<endl;
	
return 0;
}
