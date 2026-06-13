#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertHead(struct Node** headRef, int data);
void insertTail(struct Node** headRef, int data);

int main(void)
{
    struct Node* head = NULL;

    for (int i = 0; i < 3; i++)
    {
        insertHead(&head, i);
    }

    for (int i = 1; i < 3; i++)
    {
        insertTail(&head, i);
    }

    struct Node* ptr = head;
    while (ptr -> next != NULL)
    {
        int data = ptr -> data;
        printf("%d ", data);
        ptr = ptr -> next;
    }

    printf("%d\n", ptr->data);
    return 0;
}

// Function to create node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;

    return newNode;
}

// Insert data into linked list's head
void insertHead(struct Node** headRef, int data)
{
    // Create a new node
    struct Node* newNode = createNode(data);

    // Points to current head
    newNode -> next = *headRef;

    // Let newNode become the new head
    *headRef = newNode;
}

// Insert data into linked list's tail
void insertTail(struct Node** headRef, int data)
{
    struct Node* newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    // Find the lastNode
    struct Node* ptr = *headRef;
    while (ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }

    // Set last node points on New node
    ptr -> next = newNode;
}
