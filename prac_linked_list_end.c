#include <stdio.h>
#include <stdlib.h>
void insertAtBegin();
void insertAtEnd();
void insertAtMiddle();
void deletionAtBegin();
void deletionAtEnd();
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
        // case 6:
        //     printf("\n---------Deletion at Middle-------\n");
        //     deletionAtMiddle();
        //     break;
        case 7:
            printf("\n--------------Display-------------\n");
            display();
            break;
        }

    } while (option != 8);
}

//insertion at the beginning
void insertAtBegin()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number for insertion:\n");
    scanf("%d", &value);
    newnode->data = value;
    if (head == NULL)
    {
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
    }
    head = newnode;
}

//insertion at the end
void insertAtEnd()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter a number:\n");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL)
    {
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
    }
}

//insertion at the middle

void insertAtMiddle()
{
    int value, pos;
    int i = 2;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Position\n");
    scanf("%d", &pos);
    printf("Number:\n");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;
    temp = head;
    while (i <= pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

//deletion at the beginning

void deletionAtBegin()
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
}

//deletion at the end
void deletionAtEnd()
{
    struct node *lnode, *temp;
    temp = head;
    while (temp->next != NULL)
    {
        lnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
    }
    else
    {
        lnode->next = NULL;
    }

    free(temp);
}

//display the created node
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("----%d", temp->data);
        temp = temp->next;
    }
}
