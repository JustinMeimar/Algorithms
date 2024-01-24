#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
    int V;
    std::list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);

    void DFS(int v);
    void BFS(int v);

private:
    void DFSUtil(int v, std::vector<bool>& visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    
    std::vector<int> stack;
    std::vector<bool> visited(this->V, false);
    
    stack.push_back(v);
    while (stack.size() != 0) {

        int cur_node = stack.at(stack.size() -1);
        stack.pop_back();

        std::cout << "Visited: " << cur_node << std::endl;
        visited[cur_node] = true;

        std::list<int> &adj = this->adj[cur_node];
 
        for (auto it = adj.begin(); it != adj.end(); it++) {

            if (!visited[*it]) 
                stack.push_back(*it);       
        }
    } 
}



void Graph::BFS(int v) {
    // BFS logic will be implemented here
    std::queue<int> q;
    std::vector<bool> visited(this->V, false);
    
    q.push(v);
    while (q.size() != 0) {

        int cur_node = q.front();
        q.pop();
        std::cout << "Visited: " << cur_node << std::endl;
        visited[cur_node] = true;

        std::list<int> &adj = this->adj[cur_node];
 
        for (auto it = adj.begin(); it != adj.end(); it++) {

            if (!visited[*it]) 
                q.push(*it);       
        }
    } 
}

// Main function to test the graph traversal methods
int main() {
    Graph g(4); // Create a graph with 4 vertices

    // Example: adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2);

    std::cout << "Breadth First Traversal starting from vertex 2:\n";
    g.BFS(2);

    return 0;
}