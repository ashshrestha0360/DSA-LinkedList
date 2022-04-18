void push()
{
	int value;
	printf("Enter the value");
	scanf("%d", &value);
	if(top == max - 1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top ++;
		a [top] = value;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("Stack Underflow");
	}
	else
	{
		printf("%d is deleted", a[top]);\
		top --;
	}
}

void display()
{
	for(int i = top; i >= 0; i--)
	{
		if(top == -1)
		{
			printf("Stack Underflow");
		}
		else
		{
			printf("%d", a[i]);
		}
	}
}



void insert()
{
    if(rear == max - 1)
    {
        printf("Queue Overflow");
    }
    else if(front == -1)
    {
        front ++;
        rear ++;
        a[rear] = value;
    }
    else
    {
        rear ++;
        a[rear] = value;
    }
}

void delete()
{
    if(front == -1 || rear < front)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("%d is deleted", a[front]);
        front ++;
    }
}

void display()
{
    for(int i = front; i <= rear; i++)
    {
        if(front == -1 || rear < front)
        {
            printf("Queue Underflow");
        }
        else
        {
            printf("%d", a[i]);
        }
    }
}

void insert()
{
	int value;
	scanf("%d", &value);
	if(front == -1 && rear == -1)
	{
		front ++;
		rear ++;
		a[rear] = value;
	}
	else if(front == 0 && rear = max - 1 || front == rear + 1)
	{
		printf("Queue Overflow");
	}
	else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
	else
	{
		rear ++;
		a[rear] = value;
	}
}


void dequeue()
{
	if(front == -1)
	{
		printf("Queue Empty");
	}
	else if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == max - 1)
	{
		front = 0;
	}
	else
	{
		front ++;
	}
}