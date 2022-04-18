#include <stdio.h>
#include <stdlib.h>
void insertAtEnd();
void display();
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL; 
void main()
{
    int c;
    do
    {
        printf("1. Insert 2. Display 3. Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insertAtEnd();
            break;
        case 2:
            display();
            break;
        }
    } while (c != 3);
}

void insertAtEnd()
{
    struct node *head;
    int data;
    struct node *ptr, *newNode;
    int val;
    ptr = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    scanf("%d", &data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}