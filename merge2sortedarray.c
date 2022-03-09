/*ALGORITHM
Step 1:start
Step 2:read the size of array1
Step 3:enter the elements of array1
Step 4:read the size of second array
Step 5:enter the elements of array2
Step 6:initialize i=0,j=0
Step 7:while(i<m&&j<n)
Step 8:if(arr1[i]<arr[j][) then
Step 9: array3[k] = array1[i] and increment i
Step 10:else
Step 11: array3[k] = array1[j] and increment j
Step 12:increment k
Step 13:if(i>=m) then
Step 14:while(j<n)
Step 15: array3[k] = array1[j] and increment j&k
Step 16:if(j>=n) then
Step 17: array3[k] = array1[i] and increment i&k
Step 18:print the array after merging
Step 19:stop*/

#include <stdio.h>
void main()
{
    int array1[50], array2[50], array3[100], m, n, i, j, k = 0;
    printf("\n Enter size of array Array 1: ");
    scanf("%d", &m);
    printf("\n Enter sorted elements of array 1: \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &array1[i]);
    }
    printf("\n Enter size of array 2: ");
    scanf("%d", &n);
    printf("\n Enter sorted elements of array 2: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array2[i]);
    }
    i = 0;
    j = 0;
    while (i < m && j < n)
    {
        if (array1[i] < array2[j])
        {
            array3[k] = array1[i];
            i++;
        }
        else
        {
            array3[k] = array2[j];
            j++;
        }
        k++;
    }
    if (i >= m)
    {
        while (j < n)
        {
            array3[k] = array2[j];
            j++;
            k++;
        }
    }
    if (j >= n)
    {
        while (i < m)
        {
            array3[k] = array1[i];
            i++;
            k++;
        }
    }
    printf("\n After merging: \n");
    for (i = 0; i < m + n; i++)
    {
        printf("\n%d", array3[i]);
    }
}