/*ALGORITHM
Step 1:start
Step 2:create a structure DisjSet with variables n,parent[10],rank[10]
Step 3:read number of elements and assign to n
Step 4:call makeset()
Step 5:print 1.union,2.find,3.display
Step 6:read a choice and assign to ch
Step 7:if ch==1 then read the element to perform union and call union(x,y)
Step 8:if ch==2 then read the element to check if connected components
Step 9:if(find(x)==find(y)) then print connected components
Step 10:else print not connected
Step 11:ch==3 then call display()
Step 12:stop

Makeset
Step 1:start
Step 2:for i=0 to n
Step 3:parent[i]=i;
Step 4:rank[i]=0
Step 5:stop

Display disjoint set
Step 1:start
Step 2:for i=0 to dis.n
Step 3:print parent
Step 4:for i=0 to dis.n
Step 5:print rank
Step 6:find() of given item x then
Step 7:if(parent[x]!=x) then
Step 8:parent[x]=find(parent[x])
Step 9:return parent[x]
Step 10:stop

Union of disjoint set
Step 1:start
Step 2:xset=find(x),yset=find(y)
Step 3:if(xset==yset) then return they already in same set
Step 4:else
Step 5:parent[yset]=xset then
Step 6: rank[xset] = rank[xset] + 1
Step 7:dis.rank[yset]=-1
Step 8:stop*/

#include <stdio.h>
struct DisjSet
{
    int parent[10];
    int rank[10];
    int n;
} dis;
void makeSet()
{
    for (int i = 0; i < dis.n; i++)
    {
        dis.parent[i] = i;
        dis.rank[i] = 0;
    }
}
void displaySet()
{
    printf("\nParent Array\n");
    for (int i = 0; i < dis.n; i++)
    {
        printf("%d ", dis.parent[i]);
    }
    printf("\nRank Array\n");
    for (int i = 0; i < dis.n; i++)
    {
        printf("%d ", dis.rank[i]);
    }
    printf("\n");
}
int find(int x)
{
    if (dis.parent[x] != x)
    {
        dis.parent[x] = find(dis.parent[x]);
    }
    return dis.parent[x];
}
void Union(int x, int y)
{
    int xset = find(x);
    int yset = find(y);
    if (xset == yset)
        return;
    if (dis.rank[xset] < dis.rank[yset])
    {
        dis.parent[xset] = yset;
        dis.rank[xset] = -1;
    }
    else if (dis.rank[xset] > dis.rank[yset])
    {
        dis.parent[yset] = xset;
        dis.rank[yset] = -1;
    }
    else
    {
        dis.parent[yset] = xset;
        dis.rank[xset] = dis.rank[xset] + 1;
        dis.rank[yset] = -1;
    }
}
int main()
{
    int n, x, y;
    printf("How many elements ?");
    scanf("%d", &dis.n);
    makeSet();
    int ch, wish;
    do
    {
        printf("\n____MENU____\n");
        printf("1. Union \n2.Find\n3.Display\n");
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter elements to perform union");
            scanf("%d %d", &x, &y);
            Union(x, y);
            break;
        case 2:
            printf("Enter elements to check if connected components");
            scanf("%d %d", &x, &y);
            if (find(x) == find(y))
                printf("Connected components\n");
            else
                printf("Not onnected components \n");
            break;
        case 3:
            displaySet();
            break;
        }
        printf("\nDo you wish to continue ?(1/0)\n");
        scanf("%d", &wish);
    } while (wish == 1);
    return 0;
}