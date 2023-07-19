#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue implementation
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
    }
    return item;
}

// Graph implementation
typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void addEdge(Graph* graph, int src, int dest) {
    graph->vertices[src][dest] = 1;
    graph->vertices[dest][src] = 1;
}

void printGraph(Graph* graph, FILE* file) {
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            fprintf(file, "%d ", graph->vertices[i][j]);
        }
        fprintf(file, "\n");
    }
}

void BFS(Graph* graph, int startVertex, FILE* file) {
    int visited[MAX_VERTICES] = {0};
    Queue* queue = createQueue();

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    fprintf(file, "BFS traversal: ");

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        fprintf(file, "%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->vertices[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    fprintf(file, "\n");
}

int main() {
    Graph graph;
    int numVertices, maxEdges, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    graph.numVertices = numVertices;

    maxEdges = numVertices * (numVertices - 1) / 2;

    for (i = 0; i < numVertices; i++) {
        for (j = i + 1; j < numVertices; j++) {
            int random = rand() % 2;
            if (random == 1 && maxEdges > 0) {
                addEdge(&graph, i, j);
                maxEdges--;
            }
        }
    }

    FILE* file = fopen("bfs_output.txt", "w");
    if (file == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }


    printGraph(&graph, file);

    BFS(&graph, 0, file);

    fclose(file);



    return 0;
}

