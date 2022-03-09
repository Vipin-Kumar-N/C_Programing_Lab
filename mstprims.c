/*ALGORITHM
Step 1:start
Step 2:read the number of nodes and assign to n
Step 3:read the adjacency matrix
Step 4: if(cost[i][j]==0) then cost[i][j]=999
Step 5: visited[1]=1 and print node
Step 6:while(ne<n) then
Step 7:traverse adjacency matrix
Step 8:if cost[i][j]<min and if visited[i]!=0 then
Step 9:min=cost[i][j] ,a=u=I,b=v=j
Step 10:if visited[u]==0 or visited[v]==0
Step 11:print edge
Step 12:mincost+=min
Step 13:visited[b]=1
Step 14:cost[a][b]=cost[b][a]=999
Step 15:print Minimum*/

#include <stdio.h>
#include <conio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];
void main()
{
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    visited[1] = 1;
    printf("\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\nEdge %d:(%d %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost:%d\n", mincost);
}