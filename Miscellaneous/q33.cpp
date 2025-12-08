#include<iostream>
using namespace std;
#define MAX 10

void displayMatrix(int matrix[MAX][MAX], int row, int col){
	for (int i=0; i<row; i++){
	for (int j=0; j<col; j++){
	 cout<<matrix[i][j]<<"\t";
	}
	cout<<endl;
	}
}
void multiplyMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int rowA,
int colA, int rowB, int colB){
	int matrix[MAX][MAX]={0};
	for (int i=0; i<rowA; i++){
		
		for (int j=0; j<colB; j++){
			int sum=0;
			for(int k=0; k<colA; k++){
			
			
					sum=sum+matrixA[i][k]*matrixB[k][j];
					
			}
			
			matrix[i][j]=sum;
		}
		
	}
	displayMatrix( matrix,rowA, colB);
}

int main(){
	int rowA,colA,rowB,colB;
    int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	do {
	
	cout<<"Enter the number of rows and columns for the first matrix: ";
  cin>>rowA>>colA;
  if (rowA <= 0 || rowA > MAX || colA <= 0 || colA > MAX){
  	cout<<"Invalid Input"<<endl<<endl;
  	cout<<"Enter again "<<endl<<endl;
  }

  }while (rowA <=0 || rowA >MAX || colA <= 0 || colA > MAX);
  

 
  

	cout<<"Enter the elements of the first matrix: "<<endl;
	for(int i=0; i<rowA; i++){
	 for(int j=0; j<colA; j++){
	 cin>>matrixA[i][j];
	 }
	}
	
do{
	
 cout<<"Enter the number of rows and columns for the Second matrix: ";
  cin>>rowB>>colB;
  if (rowB <= 0 || rowB > MAX || colB <= 0 || colB > MAX) {
            cout << "Invalid input!." << endl<<endl;
            cout<<"Enter Again "<<endl<<endl;
        }
        
   }while (rowB <= 0 || rowB > MAX || colB <= 0 || colB > MAX );
 
    
    
    

	cout<<"Enter the elements of the Second matrix: "<<endl;
	for(int i=0; i<rowB; i++){
	 for(int j=0; j<colB; j++){
	 cin>>matrixB[i][j];
	 }
	}
	cout<<endl<<"Matrix A "<<endl<<endl;
	 displayMatrix( matrixA,rowA, colA);
	cout<<endl<<"Matrix B "<<endl<<endl;
	 displayMatrix( matrixB,rowB, colB);
	 if(colA==rowB){
	 cout<<"Multiplicatio"
	multiplyMatrices(matrixA,  matrixB, rowA,
colA, rowB, colB);
} 
else {
	cout<<"Column Of Matrix A should be Equal to Rows Of Matrix B "<<endl<<endl;
}



	
	 
	
 
  
  
}
