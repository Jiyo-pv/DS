/*  
    Graph Representation using Adjacency Matrix
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>

int main() {
    int n, i, j, edges, u, v;

    // input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adjMatrix[n][n];

    // initialize adjacency matrix to 0
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adjMatrix[i][j] = 0;

    // input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // input edges
    printf("Enter edges (source destination) - 0 based index:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        // for undirected graph, mark both [u][v] and [v][u]
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

