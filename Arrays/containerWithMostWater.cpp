#include<iostream>
#include<vector>
using namespace std;
//Brute Force Approach
/*
int mostWater(vector<int> heights){
	int n=heights.size();
	int maxArea=0;
	for(int i=0; i<n; i++){
		int currentArea=0;
	
		
	for(int j=i+1; j<n; j++){
		int width=j-i;
		currentArea=width*min(heights[i],heights[j]);
	}
	maxArea=max(maxArea,currentArea);
	}
	return maxArea;
}
*/
// Two Pointer Approach
int mostWater(vector<int> heights){
	int n=heights.size();
	int maxArea=0;
	int i=0; int j=n-1;
	while(i<j){
		int width=j-i;
		int ht=min(heights[i],heights[j]);
		int area=width*ht;
		maxArea=max(maxArea,area);
		if(heights[i]<heights[j]) i++;
		else j--;
	}
	return maxArea;
}
int main(){
	vector<int> height={1,8,6,2,5,4,8,3,7};
	cout<<"Max Area : "<<mostWater(height)<<endl;
return 0;
}
