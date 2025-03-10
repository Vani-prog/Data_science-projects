#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100  // Define maximum stack size

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++s->top] = ch;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->items[s->top--];
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    Stack s;
    initStack(&s);
    int len = strlen(str);

    // Push all characters onto the stack
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Compare characters while popping
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Palindrome
}

int main() {
    char str[MAX];

    // Take user input
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if palindrome
    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}

