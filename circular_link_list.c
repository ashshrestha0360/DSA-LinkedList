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
    struct node *next;
};
struct node *head = NULL;

void main()
{
    int option;
    do
    {
        printf("1. Insert at begin  2. Insert at end  3. Insert at middle  4. Deletion at begin  5. Deletion at end  6. Deletion at middle  7. Display  8. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertAtBegin();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            insertAtMiddle();
            break;
        case 4:
            deletionAtBegin();
            break;

        case 5:
            deletionAtEnd();
            break;

        case 6:
            deletionAtMiddle();
            break;
        case 7:
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
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insertAtEnd()
{
    int value;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number:\n");
    scanf("%d", &value);
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void insertAtMiddle()
{
    int pos, i = 2, value;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position:\n");
    scanf("%d", &pos);
    printf("Enter the number:\n");
    scanf("%d", &value);
    newnode->data = value;
    temp = head;
    while (i <= pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletionAtBegin()
{
    struct node *temp = head;
    if (temp->next == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(temp);
        head = temp->next;
    }
}

void deletionAtEnd()
{
    struct node *temp = head, *pretemp;
    if (head->next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        while (temp->next != head)
        {
            pretemp = temp;
            temp = temp->next;
        }
        pretemp->next = temp->next;
        free(temp);
    }
}

void deletionAtMiddle()
{
    int pos, i = 1;
    printf("Postion:\n");
    scanf("%d", &pos);
    struct node *temp = head, *pretemp;
    while (i != pos)
    {
        pretemp = temp;
        temp = temp->next;
        i++;
    }

    pretemp->next = temp->next;
    free(temp);
}

void display()
{
    struct node *temp = head;
    do
    {
        printf("--%d", temp->data);
        temp = temp->next;
    } while (temp != head);
}