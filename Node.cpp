#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *Next;
};
struct Node *front = NULL;

void search(int value);
void insert(int value);
void traverse(void);
void deleteNode(int value);
void reverse(void);

int main(void)
{
    insert(5);
    insert(20);
    insert(25);
    insert(30);
    printf("Traverse the linked list:\n");
    traverse();
    printf("Reversed Linked List:\n");
    reverse();

   
    return 0;
}
void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->Next = NULL;
    struct Node *current = NULL;
    if (front == NULL)
    {
        front = newNode;
    }
    else
    {
        current = front;
        while (current->Next != NULL)
        {
            current = current->Next;
        }
        current->Next = newNode;
    }
}

void traverse(void)
{
    struct Node *current = NULL;
    if (front == NULL)
    {
        printf("Empty Linked list\n");
    }
    else
    {
        current = front;
        while (current != NULL)
        {
            printf(" %d ", current->data);
            current = current->Next;
        }
    }
}

void search(int value)
{
    struct Node *current = NULL;
    if (front == NULL)
    {
        printf("Empty linked list\n");
    }
    else
    {
        current = front;
        while (current != NULL)
        {
            if (current->data == value)
            {
                printf("Value found\n");
                break;
            }
            current = current->Next;
        }
        if (current == NULL)
        {
            printf("Not found\n");
        }
    }
}

void deleteNode(int value)
{
    struct Node *current = NULL;
    struct Node *previous = NULL;
    if (front == NULL)
    {
        printf("Empty list\n");
    }
    else if (front->data == value)
    {
        current = front;
        front = front->Next;
        free(current);
        printf("Node deleted\n");
    }
    else
    {
        current = front;
        previous = current;
        current = current->Next;
        while (current != NULL)
        {
            if (current->data == value)
            {
                previous->Next = current->Next;
                free(current);
                printf("Node deleted\n");
                break;
            }
            else
            {
                previous = current;
                current = current->Next;
            }
        }
        if (current == NULL)
        {
            printf("Node not deleted\n");
        }
    }
}
void reverse (void){
	    struct Node *previousNode = NULL;
        struct Node *current = front;
        struct Node *next = NULL;
        while (current != NULL){
            next = current->Next;
            current->Next = previousNode;
            previousNode = current;

            current = next;
        }
        front = previousNode;
      
	}
