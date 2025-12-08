#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices){
	int maxProfit=0;
	int bestBuy=prices[0];
	int n=prices.size();

	for(int i=1; i<n; i++){
		if(prices[i]>bestBuy){
			maxProfit=max(maxProfit,prices[i]-bestBuy);
		
		}
		bestBuy=min(bestBuy,prices[i]);
	
	}
	return maxProfit;
}
int main(){
	vector<int> vec={3,4,5,6,7,19};
	cout<<"Max Profit: "<<maxProfit(vec)<<endl;
return 0;
}
