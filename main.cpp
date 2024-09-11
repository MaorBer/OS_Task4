#include "Graph.hpp"
#include <cstdlib>
#include <getopt.h>
#include <ctime>
#include <iostream> 

void generateRandomGraph(Graph& g, int E, int seed) {
    srand(seed);
    int V = g.getV();
    for (int i = 0; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        if (u != v) {
            g.addEdge(u, v);
        }
    }
}

int main(int argc, char* argv[]) {
    int V = 5, E = 6, seed = time(0);

    // Command-line argument parsing with getopt
    int opt;
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
            case 'v':
                V = atoi(optarg);  // Number of vertices
                break;
            case 'e':
                E = atoi(optarg);  // Number of edges
                break;
            case 's':
                seed = atoi(optarg);  // Random seed
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " [-v vertices] [-e edges] [-s seed]\n";
                exit(EXIT_FAILURE);
        }
    }

    // Create graph with V vertices
    Graph g(V);

    // Generate random graph with E edges
    generateRandomGraph(g, E, seed);

    // Print the graph
    g.printGraph();

    // Check if Euler circuit exists
    if (g.isEulerian()) {
        std::cout << "The graph has an Euler circuit!" << std::endl; // Use std::endl instead of endl
    } else {
        std::cout << "The graph does NOT have an Euler circuit." << std::endl; // Use std::endl instead of endl
    }

    return 0;
}
