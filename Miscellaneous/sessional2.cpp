#include <iostream> 
using namespace std; 
int main() {
int x = 10;
{
    int x = x;
    cout << x << "\t";
    cout << (--x);
}

 

}
/*#include <iostream> 
using namespace std; 
int main() { 
  const int N=3; 
  int A[N]={3,2,1}; 
  int B[N]={0}; 
  for(int i = 0; i < N; ++i) 
  { 
    int length = 1; 
    while (A[i] != 1) { 
  if (A[i] % 2) 
   A[i] = A[i] * 3 + 1; 
  else 
           A[i] /= 2; 
  ++length; 
 } 
 B[i]= length; 
 cout<<i<<" "<<" "<<B[i]<<endl;
   } 
   
return 0; 
}
include<iostream>
using namespace std;
int main(){

int num;
cin>>num;
for(int i=1; i<=num; i++){
	for(int j=1; j<=i; j++){
		cout<<" ";
	}
	for(int k=i; k<num; k++){
		cout<<"*";
	}
		for(int k=i; k<=num; k++){
		cout<<"*";
}
	cout<<endl;
}

      int total,i,j;
      int score[3][3]={{1,2,3},{4,5,6},{7,8,9}}	;
      for( i=0; i<3; i++){
      	total=0;
      	for( j=0; j<3; j++){
      		total+=score[j][i];
      	
		  }
		  	cout<<"sum of row "<<i+1<<" : "<<total<<endl;
	  }
	  cout<<total;
	  
	  char alphabet= 'A';
  for(int i=('F'-'A'+1);i>=1;--i)
  {
  for(int j=1;j<=i;++j)
  {
  cout<<alphabet << "";
  }
  ++alphabet;
  cout<<endl;
  }
  
   int z=5,j=7,k=6, n=3;
  cout <<(z+j%k+k * n-15)<< "\t";
  cout <<(z%n+5)<<endl;
  
  int a=5;
 
 int b=(a++)++;
 cout<<b;
 
 
 
 
 
 
 
 int x=12;
 {
 
 int x=x;
 cout<<x<<"\t";
 cout<<(--x);
}
}
*/
