#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for Queue
typedef struct {
    Node *front, *rear;
} Queue;

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

// Function to check if queue is empty
int isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

// Recursive function to reverse a queue
void reverseQueue(Queue *q) {
    if (isEmpty(q)) return;
    
    int data = dequeue(q);
    reverseQueue(q);
    enqueue(q, data);
}

// Function to print the queue
void printQueue(Queue *q) {
    Node *temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test queue reversal
int main() {
    Queue q;
    initQueue(&q);

    int n, value;
    
    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    
    printf("Enter elements of the queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }
    
    printf("Original Queue: ");
    printQueue(&q);

    // Reverse queue using recursion
    reverseQueue(&q);

    printf("Reversed Queue: ");
    printQueue(&q);

    return 0;
}

