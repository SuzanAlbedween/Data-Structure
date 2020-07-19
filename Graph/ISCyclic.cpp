// A C++ Program to detect cycle in an undirected graph 
#include<iostream> 
#include <list> 
#include <limits.h> 
using namespace std; 

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	list<int> *adj; 


	bool explore(int v,bool visited[],int parent); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	
	bool isCyclic(); 
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
// A recursive function that uses visited[] and parent to detect 
// cycle in subgraph reachable from vertex v. 
bool Graph:: explore(int v,bool visited[],int parent) 
{ 
visited[v]=true;
list<int>::iterator i; 
// Recur for all the vertices adjacent to this vertex 
for(i=adj[v].begin();i!=adj[v].end();++i)
	if(!visited[*i])
	{
		if(explore(*i,visited,v))
			return true;
	}
	else
	{
		 // If an adjacent is visited and not parent of current vertex, then there is a cycle. 
		if(*i!=parent)
			return true;
	}
return false;
		
} 

// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic()
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function to detect cycle in different 
    // DFS trees 
	for (int i = 0; i < V; i++) 
        if (!visited[i]) 
            if(explore(i, visited,-1))
				return true;
return false;
	 
} 


int main() 
{ 
	 Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? cout << "Graph contains cycle\n": cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? cout << "Graph contains cycle\n":  cout << "Graph doesn't contain cycle\n";

	return 0; 
} 
