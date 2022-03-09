/*ALGORITHM
step 1:start
step 2:enter the size of circular queue and assign to n
step 3:enter the choice
step 4:if choice=1 then do insertion
step 5:if choice=2 then do deletion
step 6:if choice=3 then display circular queue
step 8:if choice=4 then exit
step 9:stop

Insert operation
step 1:start
step 2: if ((front== 1 && rear == n) || (front == rear+ 1)) then print queue is full
step 3:elseif(front == NULL) then front =rear=1
step 4:else if (rear == n) then rear = 1
step 5:else rear++
step 6:read the element to inserted and assign to y
step 7:queue[rear]=y
step 8:stop

Delete operation
step 1:start
step 2:if(front== NULL) then print queue is empty
step 3:else
step 4:delete queue[front]
step 5:if(front==rear) then front=rear=NULL
step 6:else if(front==n) then front=1
step 7:else front ++
step 8:stop

Display circular queue
step 1:start
step 2:if (front>rear) then
step 3:for (i = front; i <=n; i++)
step 4: print queue[i])
step 5:for (i = 1; i <= rear; i++)
step 6:print queue[i]
step 7:else
step 8:for (i = front; i <= rear; i++)
step 9:print queue[i]
step 10:stop*/

#include <stdio.h>
int queue[30], n, front = 0, rear = 0, c, y;
void insert();
void delete ();
void display();
void main()
{
    printf("Enter the size of circular queue\n");
    scanf("%d", &n);
    do
    {
        printf("\t\t\nMENU\t\t\n");
        printf("\n1. Insert \n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter Choice 1-4? : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exit\n");
        }
    } while (c != 4);
}
void insert()
{
    if ((front == 1 && rear == n) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else
    {
        if (front == NULL)
            front = rear = 1;
        else if (rear == n)
            rear = 1;
        else
            rear++;
        printf("Enter the element to be inserted\n");
        scanf("%d", &y);
    }
    queue[rear] = y;
}
void delete ()
{
    if (front == NULL)
    {
        printf("Queue is empty ");
    }
    else
    {
        printf("\n %d deleted", queue[front]);
        if (front == rear)
            front = rear = NULL;
        else if (front == n)
            front = 1;
        else
            front++;
    }
}
void display()
{
    int i;
    if (front > rear)
    {
        printf("The Circular Queue is");
        for (i = front; i <= n; i++)
            printf("%d\t ", queue[i]);
        for (i = 1; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t ", queue[i]);
    }
}