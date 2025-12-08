#include<iostream>
#include<vector>
using namespace std;
void sort2Arrays(vector<int> & arr1,int m,vector<int> &arr2,int n){
	int idx=m+n-1;
	int i=m-1;
	int j=n-1;
	while(i>=0 && j>=0){
		if(arr2[j]>=arr1[i]){
			arr1[idx]=arr2[j];
			j--;
			idx--;
		}else{
			arr1[idx]=arr1[i];
			i--;
			idx--;
		}
	}
	while(j>=0){
		arr1[idx]=arr2[j];
		idx--;
		j--;
	}
}

int main(){
	vector<int> arr1={7,8,9,0,0,0};
	int m=3;
	vector<int> arr2={4,5,6};
	int n=3;
	sort2Arrays(arr1,m,arr2,n);
		for(int j:arr1){
		cout<<j<<", ";
	}
	cout<<endl;
	
return 0;
}
