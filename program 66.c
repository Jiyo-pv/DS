#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Create a new node
Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// Create a graph with n vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)calloc(vertices, sizeof(Node*)); // calloc initializes to NULL
    return graph;
}

// Add undirected edge
void addEdge(Graph* graph, int src, int dest) {
    Node* node = createNode(dest);
    node->next = graph->adjLists[src];
    graph->adjLists[src] = node;

    node = createNode(src);
    node->next = graph->adjLists[dest];
    graph->adjLists[dest] = node;
}

// Display adjacency list
void displayGraph(Graph* graph) {
    int i;
	for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Node *temp;
		for (temp = graph->adjLists[i]; temp; temp = temp->next)
            printf("-> %d ", temp->vertex);
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
	int i;
    printf("Enter edges (source destination, 0-based index):\n");
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("\nAdjacency List of the Graph:\n");
    displayGraph(graph);

    return 0;
}

