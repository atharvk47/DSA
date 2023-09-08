#include <bits/stdc++.h>
using namespace std;

// Assumptions:
// 1) This is a 1-based indexing graph. If it is a 0-based indexing graph, then change the displayMatrix(v) 
// instead of displayMatrix(v+1) inside the main function.
// 2) Given graph is an undirected graph or bidirectional graph. If it is not, remove the line AdjMatrix[v][u] inside add_edge()
// function.


// Adjacency Matrix consumes a space complexity of O(N*N) where N are the possible number of nodes in the graph.

int AdjMatrix[20][20] = {0};                       // This is an adjacency matrix initialized to zero

void displayMatrix(int v)                          // Function to display matrix
{ 
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edge(int u, int v)                       // Function to add edge into the matrix
{ 
    AdjMatrix[u][v] = 1;
    AdjMatrix[v][u] = 1;                          // Comment this line if it is not an undirected graph
}

int main()
{
    int v;                                        // Inputs the number of the vertices in the graph
    int e;                                        // Inputs the number of the edges in the graph
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int m, n;
        cin >> m >> n;
        add_edge(m, n);
    }
    displayMatrix(v + 1);                         // displayMatrix(v) if graph is 0-indexed
    return 0;
}