/*ALGORITHM
step 1:start
step 2:define a structure node
step 3:initialize value and pointers *l, *r,*t1,*t2 and assign *temp=NULL,*root=NULL
step 4:read the choice
step 5:if choice=1 then call insert()
step 6:if choice=2 then call delete()
step 7:if choice=3 then call inorder()
step 8:if choice=4 then call preorder()
step 9:if choice=5 then call postorder()
step 10:if choice=6 then exit
step 11:default print “wrong choice”
step 12:stop

To create a node
Step 1:start
Step 2:read value of node and asign to data
Step 3:temp->value=data
Step 4:temp->i=temp->r=NULL
Step 5:stop

insert a node in the tree
step 1:start
step 2:call create()
step 3:if(root== NULL) then root=temp
step 4:else
step 5:if ((temp->value > t->value) && (t->r != NULL)) then insert newnode right of
the root, search(t->r)
step 6:else if ((temp->value > t->value) && (t->r == NULL))
t->r = temp
step 7:else if ((temp->value < t->value) && (t->l != NULL)) then insert newnode left
of the root, search(t->l)
step 8:else if ((temp->value < t->value) && (t->l == NULL))
t->l = temp
step 9:stop

inorder traversal of tree
step 1: start
step 2:if(root==NULL) then exit no elements in the tree
step 3:if(t->l != NULL) then
step 4:inorder(t->l)
step 5:print t->value
step 6:if (t->r != NULL)
step 7:inorder(t->r)
step 8:stop

delete a node
step 1:start
step 2:if (root == NULL) then exit tree is empty
step 3:read the data to be deleted and assign to data
step 4:t1 = root,t2 = root
step 5:search1(root, data)
step 6:stop

preorder traversal of tree
step 1:start
step 2:if (root == NULL) then exit tree is empty
step 3:print t->value
step 4:if (t->l != NULL) then preorder(t->l)
step 5:if (t->r != NULL) then preorder(t->r)
step 6:stop

postorder traversal of tree
step 1:start
step 2:if (root == NULL) then exit tree is empty
step 3:if (t->l != NULL) then postorder(t->l)
step 4:if (t->r != NULL) then postorder(t->r)
step 5:print t->value
step 6:stop*/

#include <stdio.h>
#include <stdlib.h>
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
} *root = NULL, *temp = NULL, *t2, *t1;
void delete1();
void insert();
void delete ();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t, int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
int flag = 1;
void main()
{
    int ch;
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree\n");
    printf("3 - Inorder Traversal\n");
    printf("4 - Preorder Traversal\n");
    printf("5 - Postorder Traversal\n");
    printf("6 - Exit\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice ");
            break;
        }
    }
}
void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}
void create()
{
    int data;
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(1 * sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
}
void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}
void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}
void delete ()
{
    int data;
    if (root == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    printf("Enter the data to be deleted : ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
}
void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)
        preorder(t->l);
    if (t->r != NULL)
        preorder(t->r);
}
void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL)
        postorder(t->l);
    if (t->r != NULL)
        postorder(t->r);
    printf("%d -> ", t->value);
}
void search1(struct btnode *t, int data)
{
    if ((data > t->value))
    {
        t1 = t;
        search1(t->r, data);
    }
    else if ((data < t->value))
    {
        t1 = t;
        search1(t->l, data);
    }
    else if ((data == t->value))
    {
        delete1(t);
    }
}
void delete1(struct btnode *t)
{
    int k;
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
    else if ((t->r == NULL))
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }
    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }
    else if ((t->l != NULL) && (t->r != NULL))
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k = largest(t->l);
            flag = 2;
        }
        search1(root, k);
        t->value = k;
    }
}
int smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return (smallest(t->l));
    }
    else
        return (t->value);
}
int largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return (largest(t->r));
    }
    else
        return (t->value);
}