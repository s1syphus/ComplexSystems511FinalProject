// Example Implmentation of Kosaraju's algoirthm to print all SCCs
//From www.geeksforgeeks.org/strongly-connected-components
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{

	int V;	//Number of vertices
	list<int> *adj;	//An array of adjacency lists
	
	//Fills stack with vertices (in increasing order of finishing times)
	//The top element of stack has the maximum finishing time
	void fillOrder(int v, bool visited[], stack<int> &Stack);

	//A recursive function to print DFS starting from v
	void DFSUtil(int v, bool visited[]);
	
	public:	
		Graph(int V);
		void addEdge(int v, int w);
		
		//The main function that finds and prints strongly connected components
		void printSCCs();
		
		//Functions that returns reverse (or transpose) of this graph
		Graph getTranspose();
	};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];	
	}

//A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[]){
	//Mark the current node as visited and print it
	visited[V] = true;
	cout << v <<" ";
	
	//Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i){
		if(!visited[*i]){
			DFSUtil(*i, visited);
			}
		}	
	}
	
Graph Graph::getTranspose(){
	Graph g(V);
	for (int v = 0; v < V; v++){
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i){
			g.adj[*i].push_back(v);
			}	
		}
	return g;
	}

void Graph::addEdge(int v, int w){
	adj[v].push_Back(w); 	//add w to v's list
	}	

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack){
	//Mark the current node as visited and print it
	visited[v] = true;
	
	//Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i){
		if(!visited[*i]){
			fillOrder(*i, visited, Stack);
			}
		}
	Stack.push(v);
	}

//The main function that finds and prints all strongly connected components
void Graph::printSCCs(){
	stack<int> Stack;
	
	//Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++){
		visited[i] = false;
		}
	
	//Fill the vertices in stack according to their finishing times
	for(int i = 0; i < V; i++){
		if(visited[i] == false){
			fillOrder(i, visited, Stack);
			}
		}

	//Create a reversed Graph
	Graph gr = getTranspose();

	//Mark all the vertices as not visited (For second DFS)
	for(int i = 0; i < V; i++){
		visited[i] = false;
		}

	//Now process all vertices in order defined by Stack
	while(!Stack.empty()){
		//Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();
		
		//Print Strongly Connected Component of the popped vertex
		if(visited[v] == false){
			gr.DFSUtil(v, visited);
			cout<<endl;
			}
		}
	}	

//Driver program to test the above functions
int main(){

	

	return 0;
	}











































