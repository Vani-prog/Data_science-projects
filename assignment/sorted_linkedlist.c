#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNext;
    
    if (current == NULL)
        return;
    
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    // Taking user input for the sorted linked list
    printf("Enter the number of elements in the sorted linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the sorted linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Original linked list: \n");
    printList(head);

    removeDuplicates(head);

    printf("Linked list after removing duplicates: \n");
    printList(head);

    return 0;
}

