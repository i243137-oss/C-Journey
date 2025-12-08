#include<iostream>
using namespace std;
class Queue{
	int arr[5];
	int front , rear;
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
	void enqueue(int x){
		if(rear>=5){
			cout<<"Queue is filled"<<endl;
			return;
		}
		if(front==-1 || rear==-1){
			front++;
			rear++;
			arr[rear]=x;
		}else {
			rear++;
			arr[rear]=x;
		}
		
	}
	int deque(){
		
	}
};
int main(){
return 0;
}
