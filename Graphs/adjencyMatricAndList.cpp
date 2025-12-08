#include<iostream>
using namespace std;
class AdjencyListNode{
    public: 
    int dest;
    AdjencyListNode* next;
    AdjencyListNode(int d){
        dest=d;
        next=NULL;
    }
};
class Graph{
    int V; // Number of vertices
    bool ** adjMatrix; // Adjacency Matrix
    AdjencyListNode** adjList; // Adjacency List
    public :
    Graph(int V){
        this->V=V;
        adjMatrix=new bool * [V];
        adjList=new AdjencyListNode* [V];
        for (int i=0; i<V; i++){
            adjMatrix[i]= new bool[V];
            adjList[i]=new AdjencyListNode(0);

            
           

        }
        for(int i=0; i<V; i++){
            adjList[i]=NULL;
            for(int j=0; j<V; j++){
                adjMatrix[i][j]=false;


            }
        }
    }
    void addEdge(int src,int dest ){
        adjMatrix[src][dest]=true;
        adjMatrix[dest][src]=true; // For undirected graph
        
    }
    void printMatrix(){
        for(int i=0;i<V; i++){
            for(int j=0; j<V; j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void addInList(int src,int dest){
        AdjencyListNode* newNode=new AdjencyListNode(dest);
        newNode->next=adjList[src];
        adjList[src]=newNode;
    }       
    void printList(){
        for(int i=0; i<V; i++){
            AdjencyListNode* temp=adjList[i];
            cout<<"Adjacency list of vertex "<<i<<endl;
            while(temp){
                cout<<temp->dest<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.addInList(0,1);
    g.addInList(0,2);
    g.addInList(1,2);
    g.addInList(2,0);
    g.addInList(2,3);
    g.addInList(3,3);
    
    g.printMatrix();
    cout<<endl;
    g.printList();

    return 0;
}