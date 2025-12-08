#include<iostream>
#include<vector>
using namespace std;
int main(){
	//use of XOR
	vector<int> vec={1,3,5,5,3}; 
	vector<int> arr(30,10); // 10 10 10 
	vector<int> arr1(arr); //
	int ans=0;
	for (int val: vec){
		ans=ans^val;
	}
	cout<<"Answer: "<<ans<<endl;
	cout<<"Size "<<vec.size()<<endl;
	cout<<"Capacity "<<vec.capacity()<<endl;
	cout<<vec.at(0)<<endl;
	vec.push_back(7);
	vec.emplace_back(4);
	cout<<"Capacity "<<vec.capacity()<<endl;
	vec.pop_back();
	cout<<vec.front();
	cout<<vec.back();
	arr.erase(arr.begin());
	arr.erase(arr.begin()+2);
	// Inseart and erase are costly func
	arr.erase(arr.begin(),arr.begin()+3);  // [start,end) Erase and claer  fun cahnge size but not capacity
	arr.insert(arr.begin()+7,34);    // insert(postion,value)
	arr.clear();  //claer all elements,size becomeszero and not capacity
	cout<<arr.empty(); //tells function is emoty
	// itrators  
	// vec.begin is a pointer which point to first index  //t can derefernce *(arr.begin)
	// vec.end is pointer is pointer which points last value +1 
	vector<int> :: iterator it;
	for(it=arr.begin();it!=arr.end();it++){
		cout<<*it<<" ,";
	}
	cout<<endl;
	vector<int> :: reverse_iterator it1;
	for(it1=arr1.rbegin();it1!=arr1.rend();it1++){
		cout<<*it1<<" ,";
	}
	cout<<endl;
	
}