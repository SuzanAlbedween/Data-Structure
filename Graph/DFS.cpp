// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<bits/stdc++.h> 
using namespace std; 

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	list<int> *adj; 

	// A recursive function used by DFS 
	void explore(int v, bool visited[]); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// DFS traversal of the vertices 
	// reachable from v 
	void DFS(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph:: explore(int v, bool visited[]) 
{ 
visited[v]=true;
cout << v << " " ;
list<int>::iterator i; 
// Recur for all the vertices adjacent to this vertex 
for(i=adj[v].begin();i!=adj[v].end();++i)
	if(!visited[*i])
		explore(*i,visited);
		
} 

// DFS traversal of the vertices reachable from v. 
// It uses recursive explore() 
void Graph::DFS() 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function 
	// to print DFS traversal 
	for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            explore(i, visited); 
	 
} 


int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is Depth First Traversaln \n"; 
	g.DFS(); 

	return 0; 
} 
