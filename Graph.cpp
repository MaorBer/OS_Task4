#include "Graph.hpp"

// Node class implementation
Node::Node(int data) : data(data), next(nullptr) {}

// LinkedList class implementation
LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::push(int data) {
    Node* newNode = new Node(data);  // Create a new node with the given data
    newNode->next = head;  // Point the new node's next to the current head
    head = newNode;  // Update the head to the new node
}

void LinkedList::clear() {
    while (head) {
        Node* temp = head;  // Store the current head in a temporary pointer
        head = head->next;  // Move the head to the next node
        delete temp;  // Delete the old head
    }
}

void LinkedList::print() const {
    Node* current = head;  // Start from the head of the list
    while (current) {
        std::cout << current->data << " ";  // Print the current node's data
        current = current->next;  // Move to the next node
    }
    std::cout << std::endl;
}

// Graph class implementation
Graph::Graph(int V) : V(V), adj(V) {}

int Graph::getV() const {
    return V;
}

void Graph::addEdge(int u, int v) {
    adj[u].push(v);  // Add v to u's adjacency list
    adj[v].push(u);  // Add u to v's adjacency list (undirected graph)
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << ": ";
        adj[i].print();  // Print the adjacency list of vertex i
    }
}

bool Graph::isEulerian() {
    if (!isConnected()) {
        return false;  // Not Eulerian if graph is not connected
    }

    // Check if all vertices with non-zero degree have an even degree
    for (int i = 0; i < V; i++) {
        int degree = 0;
        Node* node = adj[i].head;
        while (node) {
            degree++;
            node = node->next;
        }
        if (degree % 2 != 0) {
            return false;  // Vertex with an odd degree
        }
    }

    return true;  // Eulerian if all vertices have even degree
}

void Graph::DFS(int v, std::vector<bool>& visited) {
    visited[v] = true;  // Mark the current node as visited

    // Visit all the adjacent vertices of v
    Node* node = adj[v].head;
    while (node) {
        int u = node->data;
        if (!visited[u]) {
            DFS(u, visited);
        }
        node = node->next;
    }
}

bool Graph::isConnected() {
    std::vector<bool> visited(V, false);

    // Find a vertex with a non-zero degree
    int start = -1;
    for (int i = 0; i < V; i++) {
        if (adj[i].head != nullptr) {
            start = i;
            break;
        }
    }

    // If there are no edges in the graph, it's Eulerian
    if (start == -1) {
        return true;
    }

    // Start DFS from the first non-zero degree vertex
    DFS(start, visited);

    // Check if all vertices with non-zero degree are visited
    for (int i = 0; i < V; i++) {
        if (adj[i].head != nullptr && !visited[i]) {
            return false;  // Not connected
        }
    }

    return true;
}
