#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

// Node class representing an element in the adjacency list
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node in the list

    // Constructor to initialize a node with data
    Node(int data);
};

// LinkedList class representing an adjacency list for a vertex
class LinkedList {
public:
    Node* head;    // Pointer to the head of the linked list

    // Constructor
    LinkedList();

    // Push a new node to the front of the list
    void push(int data);

    // Clear the list and free memory
    void clear();

    // Print the list contents
    void print() const;
};

// Graph class representing an undirected graph
class Graph {
private:
    int V;   // Number of vertices
    std::vector<LinkedList> adj;  // Adjacency list representation

    // Perform DFS from a given vertex
    void DFS(int v, std::vector<bool>& visited);

    // Check if the graph is connected
    bool isConnected();

public:
    // Constructor to initialize a graph with V vertices
    Graph(int V);

    // Get the number of vertices
    int getV() const;

    // Add an edge between vertices u and v
    void addEdge(int u, int v);

    // Print the graph
    void printGraph();

    // Check if the graph has an Eulerian circuit
    bool isEulerian();
};

#endif
