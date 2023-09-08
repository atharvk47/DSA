#include <bits/stdc++.h>
using namespace std;

// Assumption:
// 1) This is a 1-based indexing graph. If it is a 0-based indexing graph, then change the size of the vector as v 
// instead of v+1 inside the declaration of adj vector inside main function.
// 2) Given graph is an undirected graph or bidirectional graph. If it is not, remove the line adj[d].push_back(s) inside add_edge()
// function.

void addEdge(vector<int> adj[], int s, int d) {      // Function used to add an edge
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void printGraph(vector<int> adj[], int V) {          // Function used to print the entire graph
  for (int d = 0; d <= V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  int V;
  cin >> V;                                          // Input the number of vertices present in the graph

  vector<int> adj[V+1];                              // Declaring an array of vectors as adjacency list

  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  addEdge(adj, 4, 5);
  printGraph(adj, V);

  return 0;
}