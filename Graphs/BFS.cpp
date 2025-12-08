#include<iostream>
using namespace std;
#include<queue>
class Graph{
    public:
    int V; // Number of vertices
    bool ** adjMatrix;
    Graph(int V){
    	this->V=V;
    	adjMatrix=new bool *[V+1];
    	for (int i=0; i<V; i++){
    		adjMatrix[i]= new bool [V+1];
    		
		}
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                adjMatrix[i][j]=false;
            }
        }
	}
	void addEdge(int src,int dest){
		adjMatrix[src][dest]=true;
		adjMatrix[dest][src]=true;
		
	}

};
void BFS(Graph G, int i){
	bool visted[G.V]={0};
	queue<int> q;
	visted[i]=true;
	q.push(i);
	cout<<"BFS "<<i<<" ";
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0; i<G.V;i++){
			if(G.adjMatrix[u][i] && !visted[i]){
				q.push(i);
				cout<<i<<" ";
				visted[i]=true;
			}
		}
	}
}
int main(){
    Graph G(8); // 8 vertices
    // Add edges according to the adjacency matrix in the attachment
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(1, 5);
    G.addEdge(1, 6);
    G.addEdge(1, 7);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(2, 5);
    G.addEdge(2, 6);
    G.addEdge(2, 7);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(3, 6);
    G.addEdge(3, 7);
    G.addEdge(4, 5);
    G.addEdge(4, 6);
    G.addEdge(4, 7);
    G.addEdge(5, 6);
    G.addEdge(5, 7);
    G.addEdge(6, 7);
    BFS(G, 1);
    return 0;
}