#include <stdio.h>

void main()
{
    int n,ctr=0;
    int i, j, k;


    printf("Input the number of elements You wanna work with : \n");
    scanf("%d",&n);

    printf("Input the  elements of  the array : \n");
    int arr[n];

    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nThe unique elements found in the array are : \n");
    for(i=0; i<n; i++)
    {
        ctr=0;

        for(k=i+1; k<n; k++)
        {
            if(arr[i]== arr[k])
            {
                ctr++;
            }
        }

        if(ctr == 0)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n\n");
}
