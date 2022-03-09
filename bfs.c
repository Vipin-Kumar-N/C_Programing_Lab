/*ALGORITHM
Step 1:start
Step 2:enter the number of vertices
Step 3:read the graph in matrix form
Step 4:enter the starting vertex
Step 5:repeat the step4&5 until the queue is empty
Step 6:take the front item of the queue and add it to the visited list
Step 7:create a list of that vertex adjacent node.Add the one which aren’t in the
Visited list to the back of the queue
Step 8:stop*/

#include <stdio.h>
#include <conio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        printf("%d\t", q[f]);
        bfs(q[f++]);
    }
}
void main()
{
    int v;
    printf("Enter the no of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    printf("\nEnter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("\nEnter the starting vertex:");
    scanf("%d", &v);
    visited[v] = 1;
    printf("%d", v);
    bfs(v);
    getch();
}