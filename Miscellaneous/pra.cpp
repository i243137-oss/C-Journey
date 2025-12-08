#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int i,j,rows;
    cout << "Ennter the number of rows" << endl;
    cin>>rows;  //Takes input from the user
    cout<<"\n";
    for(i=1; i<=rows; i++){
  for(j=i; j<=rows; j++){
  cout<<" ";//print space
  }
  for(j=1; j<=2*i-1; j++){
  cout<<j;
  }
   for(j=2*i; j<=2*rows-1; j++){
  cout<<" ";//print space
   }
  for(j=1; j<=2*i-1; j++){
  cout<<j;  //print number
  }
   for(j=i; j<=rows; j++){
  cout<<" ";//print space
  }
  for(j=1; j<=2*i-1; j++){
  cout<<j;
  }
   for(j=2*i; j<=2*rows-1; j++){
  cout<<" ";//print space
   }
  for(j=1; j<=2*i-1; j++){
  cout<<j;  //print number
  }
  cout<<"\n";

}
getch();
    return 0;
}
