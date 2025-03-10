#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent an adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

// Function to create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function to detect cycle in an undirected graph
bool detectCycleDFS(struct Graph* graph, int vertex, int parent) {
    graph->visited[vertex] = true;
    struct Node* temp = graph->adjLists[vertex];
    
    while (temp != NULL) {
        if (!graph->visited[temp->vertex]) {
            if (detectCycleDFS(graph, temp->vertex, vertex)) {
                return true;
            }
        } else if (temp->vertex != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to check if the graph contains a cycle
bool hasCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (detectCycleDFS(graph, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

// Main function
int main() {
    int vertices, edges, src, dest;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);
    
    struct Graph* graph = createGraph(vertices);
    
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    if (hasCycle(graph)) {
        printf("Graph contains a cycle.\n");
    } else {
        printf("Graph does not contain a cycle.\n");
    }
    
    return 0;
}

