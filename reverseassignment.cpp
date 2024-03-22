#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;

void insert(int value);
void traverse(void);
void search(int value);
void deletenode(int value);
void reverse(void);

int main(void){
    insert(5);
    insert(25);
    insert(20);
    insert(30);
    //deletenode(20);
    search(20);
    //traverse();
    printf("\n\n");
    reverse();
    traverse();
    return 0;
}
void insert(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    struct Node *current = NULL;

    if(front==NULL){
        front = newNode;
    }
    else{
        current = front;
        while (current->next != NULL){
        	current = current->next;
		}
		current->next = newNode;
    }
}
void traverse(void){
	struct Node *current = NULL;
	if(front == NULL){
		printf("Empty linked list");
	}
	else{
		current = front;
		while(current != NULL){
			printf("%d ",current->data);
			current = current->next;
		}
	}
}
void search(int value){
	struct Node *current = NULL;
	if(front == NULL){
		printf("Empt linked list\n\n");
	}
	else{
		current = front;
		while(current != NULL){
			if(current->data == value){
				printf("Value found\n\n");
				break;
			}
			current=current->next;
			if(current==NULL)
				printf("Value not found\n\n");
		}
	}
}
void deletenode(int value){
	struct Node *current = NULL;
	struct Node *previous = NULL;
	if(front == NULL){
		printf("Empty list\n\n");
	}
	else if (front->data == value){
		current = front;
		front = front->next;
		free(current);
	} else {
		current = front;
		previous = current;
		current = current->next;
		while(current != NULL){
			if(current->data == value){
				previous->next = current->next;
				free(current);
				printf("node deleted \n\n");
				break;
			}
			else{
				previous = current;
				current = current->next;
			}
			if(current == NULL){
				printf("Node not deleted\n\n");
			}
		}
	}
}

	void reverse (void){
	    struct Node *previous = NULL;
        struct Node *current = front;
        struct Node *next = NULL;
        while (current != NULL){
            next = current->next;
            current->next = previous;
            previous = current;

            current = next;
        }
        front = previous;
	}




