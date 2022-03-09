/*ALGORITHM
Step 1:start
Step 2:Define a structure ‘node’ with two member val and next
Step 3:Define a node pointer head
Step 4:enter the choice
Step 5:if choice==1 then do push operation
Step 6: if choice==2 then do pop operation
Step 7:if choice==3 then display linked list
Step 8:if choice==4 then exit
Step 9:stop

Push operation
Step 1:start
Step 2:create a new node
Step 3:if(head==NULL) then
Step 4:ptr->val=val
Step 5:ptr->next=NULL
Step 6:head=ptr
Step 7:else
Step 8:ptr->val = val
Step 9:ptr->next = head
Step 10:head=ptr
Step 11:print item pushed
Step 12:stop

Pop operation
Step 1:start
Step 2:if(head==NULL) then
Step 3:print underflow
Step 4:else
Step 5:item = head->val
Step 6:ptr = hea
Step 7:head = head->next
Step 8:free(ptr)
Step 9:print Item popped
Step 10:stop

Display linked list
Step 1:start
Step 2:if (ptr==NULL) then
Step 3:print stack is empty
Step 4:else
Step 5:while(ptr!=NULL)
Step 6:print the elments in the stack
Step 7:stop*/

#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
    int val;
    struct node *next;
};
struct node *head;
void main()
{
    int choice = 0;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
}
void push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        printf("Enter the value");
        scanf("%d", &val);
        if (head == NULL)
        {
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
        printf("Item pushed");
    }
}
void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");
    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}