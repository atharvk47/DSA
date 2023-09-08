#include <bits/stdc++.h>
using namespace std;

int AdjMatrix[20][20] = {0};                      // This is an adjacency matrix initialized to zero.

void displayMatrix(int v)
{ // Function to display matrix
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edge(int u, int v)
{ // Function to add edge into the matrix
    AdjMatrix[u][v] = 1;
    AdjMatrix[v][u] = 1;
}

int main()
{
    int v;                                        // Inputs the name of the vertices
    int e;                                        // Inputs the number of vertices
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int m, n;
        cin >> m >> n;
        add_edge(m, n);
    }
    displayMatrix(v + 1);
    return 0;
}