/*ALGORITHM
step 1:start
step 2:define a structure node
step 3:initialize data and pointers *previous, *next and assign *head=NULL
step 4:read the choice
step 5:if choice=1 then do insert at a position
step 6:read the value to inserted and assign to value
step 7:select the insertion position
step 8:if ch=1 then insert at beginning
step 9:if ch=2 then isert at end
step 10:if ch=3 then insert after a node
step 11:if choice=2 then do select the deleting position
step 12:if ch=1 then delete at beginning
step 13:if ch=2 then delete at end
step 14:if ch=2 then delete a specific node
step 15:if choice=3 then do
step 16: if(head == NULL) then print List is Empty
step 17: else initialize *temp=head
step 18: while(temp -> next != NULL)
step 19:print temp->data
step 20:if choice=4 then exit
step 21:stop

Insert at beginning
step 1:start
step 2:create a newNode
step 3:newNode->data=value
step 4:newNode->previous=NULL
step 5:if (head==NULL) then
step 6: newNode->next=NULL
step 7:head=newNode
step 8:else newNode->next=NULL
step 9:head=newNode
step 10:print insertion success
step 11:stop

Insert at end
step 1:start
step 2:create a newNode
step 3:newNode->data=value
step 4:newNode->next=NULL
step 5:if(head==NULL) then
step 6:newNode -> previous = NULL
step 7:head = newNode
step 8:else
step 9:*temp=head
step 10:while(temp->next!=NULL)
step 11:temp=temp -> next
step 12:temp -> next = newNode
step 13:newNode -> previous = temp
step 14:print insertion success
step 15:stop

Insert after a node
step 1:start
step 2:input the data and location
step 3:create a newNode
step 4:newNode -> data = value
step 5:if(head == NULL) then
step 6:newNode -> previous = newNode -> next = NULL
step 7:head = newNode
step 8:else
step 9:initialize *temp1=head,temp2
step 10:while(temp1 -> data != location)
step 11:if(temp1 -> next == NULL) then
step 12:print Given node is not found in the list
step 13:else
step 14:temp1= temp1 -> next
step 15: temp2 = temp1 -> next
step 16:temp1 -> next = newNode
step 17:newNode -> previous = temp1
step 19:newNode -> next = temp2
step 20:temp2 -> previous = newNode
step 21:print insertion success
step 22:stop

Delete at beginning
step 1:start
step 2:if (head==NULL) then print list is empty and deletion is not possible
step 3:else initialize *temp=head
step 4:if(temp -> previous == temp -> next) then
step 5:head=NULL
step 6:free(temp)
step 7:else
step 8:head = temp -> next
step 9:head -> previous = NULL
step 10:free(temp)
step 11:print deletion success
step 12:stop

Delete at end
Step 1:start
step 2:if (head==NULL) then print list is empty and deletion is not possible
step 3:else initialize *temp=head
step 4:if(temp -> previous == temp -> next) then
step 5:head=NULL
step 6:free(temp)
step 7:else
step 8:while(temp-> next != NULL)
step 9:temp = temp -> next
step 10:temp -> previous -> next = NULL
step 11:free(temp)
step 12:print deletion success
step 13:stop

Delete a specific node
Step 1:start
step 2:if (head==NULL) then print list is empty and deletion is not possible
step 3:else initialize *temp=head
step 4:while(temp -> data != delValue)
step 5:if(temp -> next == NULL)
step 6:print Given node is not found in the list
step 7:else initialize temp=temp->next
step 8: if(temp == head)
step 9:head = NULL
step 10:free(temp)
step 11:else
step 12:temp -> previous -> next = temp -> next
step 13:free(temp)
step 14:print deletion success
step 15:stop*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev, *next;
};
struct node *start = NULL;
void traverse()
{
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}
void insertAtFront()
{
    int data;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
}
void insertAtEnd()
{
    int data;
    struct node *temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = NULL;
    trav = start;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}
void insertAtPosition()
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter position : ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;
    temp = start;
    if (start == NULL)
    {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else if (pos == 1)
    {
        newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}
void deleteFirst()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}
void deleteEnd()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else
    {
        temp->prev->next = NULL;
        free(temp);
    }
}
void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter position : ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            position = start;
            start = start->next;
            if (start != NULL)
            {
                start->prev = NULL;
            }
            free(position);
            return;
        }
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;
        free(position);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at"
               " starting\n");
        printf("\t3 For insertion at"
               " end\n");
        printf("\t4 For insertion at "
               "any position\n");
        printf("\t5 For deletion of "
               "first element\n");
        printf("\t6 For deletion of "
               "last element\n");
        printf("\t7 For deletion of "
               "element at any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}