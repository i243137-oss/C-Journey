#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralMatrix(vector<vector<int>> arr){
	vector<int> ans;
	int m=arr.size();
	int n=arr[0].size();
	int stRow=0;
	int endRow=m-1;
	int stCol=0;
	int endCol=n-1;
	while(stRow<=endRow && stCol<=endCol ){
		for(int i=stCol; i<=endCol; i++){
			ans.push_back(arr[stRow][i]);
		}
		for (int i=stRow+1; i<=endRow;i++){
			ans.push_back(arr[i][endCol]);
		}
		for(int i=endCol-1; i>=stCol;i--){
			if(stCol==endCol)break;
			ans.push_back(arr[endRow][i]);
		}
		for(int i=endRow-1; i>=stRow+1; i--){
			if(stRow==endRow) break;
			ans.push_back(arr[i][stCol]);
		}
		stRow++;
		stCol++;
		endRow--;
		endCol--;
		
	}
	return ans;
}
int main(){
		vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
		for(int i: spiralMatrix(arr)){
			cout<<i<<", ";
		}
		cout<<endl;
return 0;
}
