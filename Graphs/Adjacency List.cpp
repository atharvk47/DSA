#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void printGraph(vector<int> adj[], int V) {
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
  cin >> V;

  vector<int> adj[V+1];

  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  addEdge(adj, 4, 5);
  printGraph(adj, V);

  return 0;
}