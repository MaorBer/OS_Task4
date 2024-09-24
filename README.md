# OS_Task4

## Overview
This project implements a graph data structure and checks for the existence of an Eulerian circuit. The tasks involve creating a random graph, validating Eulerian properties, and using profiling tools to measure performance and memory usage.

## Features
1. **Graph Implementation**: A graph is represented using adjacency lists, with support for adding edges and checking for Eulerian circuits.
2. **Eulerian Circuit Detection**: The program checks whether the graph has an Eulerian circuit based on its connectedness and vertex degrees.
3. **Command-Line Arguments**: The program accepts parameters for the number of vertices (`-v`), edges (`-e`), and random seed (`-s`) using `getopt`.
4. **Testing**: Predefined tests are provided to validate the correctness of the Eulerian circuit detection.

## Tasks Breakdown
- **Task 1**: Create the graph structure, add edges, and implement Eulerian circuit detection.
- **Task 2**: Test the graph with predefined cases to ensure correctness.
- **Task 3**: Generate a random graph using the provided parameters and check for Eulerian circuits.
- **Task 4**: Use profiling tools (like Valgrind, GProf, and GCov) to analyze the program.

## How to Build
Use the provided Makefile to build the project:

```bash
make

