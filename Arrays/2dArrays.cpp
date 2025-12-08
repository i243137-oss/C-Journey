#include<iostream>
using namespace std;
pair<int,int> linearSearch(int arr[][3],int rows,int cols,int key){
	for(int i=0; i<rows;i++){
		for(int j=0;j<cols;j++){
			if(arr[i][j]==key){
				return {i,j};
			}
		}
	}
	return {-1,-1};
}
int maxRowSum(int arr[][3],int rows,int cols){
	int maxSum=INT_MIN;
	for(int i=0; i<rows;i++){
		int sum=0;
		for(int j=0;j<cols;j++){
		       sum+=arr[i][j];
			}
			
			maxSum=max(maxSum,sum);
			
		}
	return  maxSum;
}
int maxColSum(int arr[][3],int rows,int cols){
	int maxSum=INT_MIN;
	for(int i=0; i<cols;i++){
		int sum=0;
		for(int j=0;j<rows;j++){
		       sum+=arr[j][i];
			}
			
			maxSum=max(maxSum,sum);
			
		}
	return  maxSum;
}
int diagSum(int arr[][3],int rows,int cols){
	int sum=0;
	for(int i=0;i<rows;i++){
		sum+=arr[i][i];                   //primarySum
		int j=rows-1-i;
		if(i!=j){
			sum+=arr[i][j];             //Secondary Sum
		}
	}
/*
	for(int i=0; i<cols;i++){
	
		for(int j=0;j<rows;j++){
			if(i==j)
		       sum+=arr[j][i];
		       else if(j==rows-1-i)
		        sum+=arr[j][i];
			}
			
		
			
		}
		*/
	return  sum;
	
}
int main(){
	int arr[][3]={{1,2,3},{5,6,7}};
	int arr1[3][3]={1,2,3,4,5,6,7,8,9};
	pair<int,int> pos=linearSearch(arr,2,3,3);
	cout<<"Position of 3 is "<<pos.first<<" and "<<pos.second<<endl;
	cout<<"Max Row Sum is "<<maxRowSum(arr,2,3)<<endl;
	cout<<"Max Col Sum is "<<maxColSum(arr,2,3)<<endl;
	cout<<"Diagnol Sum is "<<diagSum(arr1,3,3)<<endl;
	
return 0;
}
