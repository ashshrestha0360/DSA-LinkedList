#include <stdio.h>
#include <stdlib.h>
void insertAtBegin();
void insertAtEnd();
void insertAtMiddle();
void deletionAtBegin();
void deletionAtEnd();
void deletionAtMiddle();
void display();
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void main()
{
    int option;
    do
    {
        printf("----------------------------------------------------------------------------");
        printf("\n 1. Insert at Begin \n 2. Insert at End \n 3. Insert at Middle \n 4. Delete at Begin \n 5. Delete at End \n 6. Delete at Middle \n 7. Display \n 8. Exit \n");
        printf("---------------------------------------------------------------------------\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n--------Insertion at Begin--------\n");
            insertAtBegin();
            break;

        case 2:
            printf("\n---------Insertion at End---------\n");
            insertAtEnd();
            break;
        case 3:
            printf("\n--------Insertion at Middle--------n");
            insertAtMiddle();
            break;
        case 4:
            printf("\n--------Deletion at Begin---------\n");
            deletionAtBegin();
            break;
        case 5:
            printf("\n---------Deletion at End----------\n");
            deletionAtEnd();
            break;
        case 6:
            printf("\n---------Deletion at Middle-------\n");
            deletionAtMiddle();
            break;
        case 7:
            printf("\n--------------Display-------------\n");
            display();
            break;
        }

    } while (option != 8);
}

void insertAtBegin()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number:\n");
    scanf("%d", &value);
    newnode->data = value;
    if (head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
    {
        newnode->prev = NULL;
        newnode->next = head;
    }
    head = newnode;
    printf("Inserted successfully!");
}

void insertAtEnd()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number:\n");
    scanf("%d", &value);
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }

    printf("Inserted successfully!");
}

void insertAtMiddle()
{
    int i = 1, value, pos;
    struct node *newnode, *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position\n");
    scanf("%d", &pos);
    printf("Enter the number:\n");
    scanf("%d", &value);
    newnode->data = value;
    while (i < (pos - 1))
    {
        temp = temp->next;
        i++;
    }

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;

    printf("Inserted successfully!");
}

void deletionAtBegin()
{
    head->prev = NULL;
    free(head->prev);
}

void deletionAtEnd()
{
    struct node *temp = head;
    temp->prev->next = NULL;
    free(temp);
}

void deletionAtMiddle()
{
    struct node *temp = head;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d---", temp->data);
        temp = temp->next;
    }
}
