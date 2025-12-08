#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute Force Approach
/*
int majorityElement(vector <int> &num){
	int n=num.size();
	for(int val :num){
		int freq=0;
		for(int vel :num){
			if(vel==val){
				freq++;
			}
		}
		if(freq>n/2){
			return val;
		}
	}
	return -1;
}
*/
//Slightly Optimized Approach
/*
int majorityElement(vector <int> &num){
	int n=num.size();
    sort(num.begin(),num.end());
    int freq=1;
    int ans=num[0];
    for(int i=1; i<n;i++){
    	if(num[i]==num[i-1]){
    		freq++;
    		if(freq>n/2){
    			return ans;
			}
		}else{
			freq=0;
			ans=num[i];
		}
	}
    return ans;
}
*/
//Moores Algoritm

int majorityElement(vector <int> &num){
	int n=num.size();
    int freq=0; int ans=0;
    for(int i=0; i<n; i++){
    	if(freq==0){
    		ans=num[i];
    		freq=1;
    	
		}else if(ans==num[i]) freq++;
		else freq--;
	
	}
    return ans;
}
int main(){
	vector<int>vec={1,2,2,1,1};
	cout<<"Majority element is : "<<majorityElement(vec)<<endl;
return 0;
}
