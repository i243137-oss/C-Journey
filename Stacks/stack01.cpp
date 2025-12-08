#include<iostream>
#include<vector>
using namespace std;
class Stack{
	vector<int> arr;
	public:
		void push(int val){
			arr.push_back(val);
		}
		void pop(){
			arr.pop_back();
		}
		int top(){
			return arr[arr.size()-1];
		}
		bool empty(){
			return arr.size()==0;
		}
};
int main(){
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
return 0;
}
