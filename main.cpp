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

// Function to run predefined tests
void runGraphTests() {
    std::cout << "Running Graph Tests...\n";

    // Test 1: Graph with no edges (Eulerian circuit should not exist)
    std::cout << "\nTest 1: Graph with no edges\n";
    Graph g1(5);
    g1.printGraph();
    if (g1.isEulerian()) {
        std::cout << "Test 1 Failed: The graph has an Euler circuit (shouldn't).\n";
    } else {
        std::cout << "Test 1 Passed: The graph does NOT have an Euler circuit.\n";
    }

    // Test 2: Graph with an Eulerian circuit
    std::cout << "\nTest 2: Graph with an Eulerian circuit\n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);
    g2.printGraph();
    if (g2.isEulerian()) {
        std::cout << "Test 2 Passed: The graph has an Euler circuit.\n";
    } else {
        std::cout << "Test 2 Failed: The graph does NOT have an Euler circuit (should have).\n";
    }

    // Test 3: Graph with vertices having odd degree (Eulerian circuit should not exist)
    std::cout << "\nTest 3: Graph with vertices having odd degree\n";
    Graph g3(5);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 4);
    g3.printGraph();
    if (g3.isEulerian()) {
        std::cout << "Test 3 Failed: The graph has an Euler circuit (shouldn't).\n";
    } else {
        std::cout << "Test 3 Passed: The graph does NOT have an Euler circuit.\n";
    }

    // Test 4: Disconnected graph (Eulerian circuit should not exist)
    std::cout << "\nTest 4: Disconnected graph\n";
    Graph g4(6);
    g4.addEdge(0, 1);
    g4.addEdge(2, 3);
    g4.printGraph();
    if (g4.isEulerian()) {
        std::cout << "Test 4 Failed: The graph has an Euler circuit (shouldn't).\n";
    } else {
        std::cout << "Test 4 Passed: The graph does NOT have an Euler circuit.\n";
    }

    std::cout << "Graph Tests Completed.\n";
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
        std::cout << "The graph has an Euler circuit!" << std::endl;
    } else {
        std::cout << "The graph does NOT have an Euler circuit." << std::endl;
    }

    // Run predefined tests
    runGraphTests();

    return 0;
}
