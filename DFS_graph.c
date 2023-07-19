#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100

// Stack data structure
typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

// Graph data structure
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Stack operations
void initializeStack(Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int vertex) {
    stack->items[++stack->top] = vertex;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top--];
}

// Graph operations
void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void depthFirstSearch(Graph* graph, int startVertex, bool visited[], Stack* stack) {
    visited[startVertex] = true;
    push(stack, startVertex);

    while (!isStackEmpty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                push(stack, i);
            }
        }
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize graph
    Graph graph;
    initializeGraph(&graph, numVertices);

    // Generate random edges
    srand(time(NULL));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j) {
                int random = rand() % 2;  // Generate 0 or 1 randomly
                if (random == 1) {
                    addEdge(&graph, i, j);
                }
            }
        }
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph.adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Perform DFS
    bool visited[MAX_VERTICES] = { false };
    Stack stack;
    initializeStack(&stack);

    int startVertex;
    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("\nDFS traversal: ");
    depthFirstSearch(&graph, startVertex, visited, &stack);
       printf("\n");

    // Store output in a separate file
    FILE* outputFile = fopen("dfs.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(outputFile, "DFS traversal: ");
    for (int i = 0; i < numVertices; i++) {
        fprintf(outputFile, "%d ", stack.items[i]);
    }

    fclose(outputFile);

    return 0;
}
