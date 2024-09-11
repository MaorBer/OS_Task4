#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* next;

    Node(int data);
};

class LinkedList {
public:
    Node* head;

    LinkedList();
    void push(int data);
    void clear();
    void print() const;
};

class Graph {
private:
    int V;  // Number of vertices
    std::vector<LinkedList> adj;  // Array of linked lists for adjacency list

public:
    Graph(int V);  // Constructor
    void addEdge(int u, int v);  // Add an edge
    void printGraph();  // Print the graph's adjacency list
    bool isEulerian();  // Check if the graph is Eulerian
    bool isConnected();  // Check if the graph is connected
    int getV() const;  // Getter for V

private:
    void DFS(int v, std::vector<bool>& visited);  // Depth-First Search helper function
};
