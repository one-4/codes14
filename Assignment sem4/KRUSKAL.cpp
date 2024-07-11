#include <iostream>
using namespace std;
#define MAX 100 // Maximum number of edges
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    Edge edges[MAX];
};

// A structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    return graph;
}
// Function to find set of an element i (uses path compression technique)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges according to their weights
void sortEdges(Graph* graph) {
    for (int i = 0; i < graph->E - 1; ++i) {
        for (int j = 0; j < graph->E - i - 1; ++j) {
            if (graph->edges[j].weight > graph->edges[j + 1].weight) {
                Edge temp = graph->edges[j];
                graph->edges[j] = graph->edges[j + 1];
                graph->edges[j + 1] = temp;
            }
        }
    }
}

// Main function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX]; // This will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sortEdges(graph);

    // Allocate memory for creating V subsets
    Subset* subsets = new Subset[V];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it in result
        // and increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // Print the contents of result[] to display the built MST
    cout << "Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;

    delete[] subsets;
}
int main() {
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph* graph = createGraph(V, E);
    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    // add edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    // add edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    // add edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    // add edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);
    return 0;
}
