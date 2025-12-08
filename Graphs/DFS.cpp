#include<iostream>
using namespace std;

class Graph{
    public:
    int V; 
    bool ** adjMatrix;
    
    Graph(int V){
        this->V = V;
        // Allocate size V+1 to be safe for 1-based indexing
        adjMatrix = new bool *[V+1];
        
        // FIX: Loop must go up to <= V to initialize ALL rows
        for (int i = 0; i <= V; i++){
            adjMatrix[i] = new bool [V+1];
            for(int j = 0; j <= V; j++){
                adjMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int src, int dest){
        adjMatrix[src][dest] = true;
        adjMatrix[dest][src] = true;
    }
};

// FIX 1: Pass Graph by reference (&) to save memory
// FIX 2: Do NOT allocate 'new' array here. Just use the one passed from main.
void DFS(Graph &G, int vertex, bool *visited){
    
    cout << vertex << " ";
    visited[vertex] = true; // Mark current node
    
    // Loop from 1 to V (since your graph uses 1-based indexing)
    for(int i = 1; i <= G.V; i++){
        if(G.adjMatrix[vertex][i] == true && !visited[i]){
            DFS(G, i, visited); // Just pass the pointer along
        }
    }
}

int main(){
    Graph G(8); 
    
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

    // FIX 3: Allocate the array ONCE here in main
    bool* visited = new bool[G.V + 1];
    
    // Initialize it
    for(int i = 0; i <= G.V; i++) {
        visited[i] = false;
    }

    cout << "DFS Traversal starting from vertex 1: ";
    
    DFS(G, 1, visited);
    
    // Cleanup memory at the very end
    delete[] visited; 
    
    return 0;
}