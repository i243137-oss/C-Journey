#include <iostream>
#include <climits>
using namespace std;

const int I = INT_MAX;

// 1. Fixed Matrix Symmetry (1-6 cost must be same as 6-1)
int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},   // Node 1: (1,6)=5 was 15 in your code
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},   // Node 6
    {I, I, 10, I, 14, 18, I, I}
};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][6]; // Stores the 6 edges of the result tree

int main()
{
    int i, j, k, u, v, min;
    int n = 7;
    min = I;

    // --- STEP 1: Find the first Minimum Edge ---
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    } // <--- ERROR 1: You forgot to close this loop!
    
    // --- STEP 2: Initialize the Tree ---
    t[0][0] = u;
    t[1][0] = v;
    near[u] = 0;
    near[v] = 0; // <--- ERROR 2: You used 'k' here (it was empty), changed to 'v'

    // --- STEP 3: Initialize Near Array ---
    for(int i = 1; i <= n; i++){ // <--- ERROR 3: Syntax 'int=1' fixed
        if(near[i] != 0){        // Check only unvisited nodes
            if(cost[i][u] < cost[i][v]){
                near[i] = u;
            } else {
                near[i] = v;     // <--- ERROR 4: You used 'j' (undefined), changed to 'i'
            }
        }
    }

    // --- STEP 4: Find remaining n-2 edges ---
    for (int i = 1; i < n-1; i++){
        min = I;
        
        // Find next nearest node
        for(int j = 1; j <= n; j++){
            if(near[j] != 0 && cost[j][near[j]] < min){
                min = cost[j][near[j]];
                k = j; 
            }
        }

        // Add to Tree
        t[0][i] = k;
        t[1][i] = near[k]; // <--- ERROR 5: Fixed index logic
        near[k] = 0;       // Mark as visited

        // --- MISSING STEP: Update Near Array for the new node 'k' ---
        // You completely missed this loop in your code!
        for(int j = 1; j <= n; j++){
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]]){
                near[j] = k;
            }
        }
    }

    // Print Result
    cout << "Minimum Spanning Tree Edges:" << endl;
    for(int i=0; i<n-1; i++){
        cout << "(" << t[0][i] << ", " << t[1][i] << ")" << endl;
    }

    return 0;
}