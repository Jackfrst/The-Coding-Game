
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int a[20],beg,end,mid,n,i,item;

    printf("Enter how many Numbers:");
    scanf("%d",&n);
    printf("Enter %d sorted number:",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter Search Item:");
    scanf("%d",&item);
    beg=0;
    end=n-1;
    mid= int (beg+end)/2;

    while (beg<=end && a[mid]!=item)
    {
       if(item>a[mid])
            beg=mid+1;
       else
        end=mid-1;


        mid= (beg+end)/2;
    }
    if(a[mid]==item)
        printf("Search is Successful at position=%d",mid+1);
    else
        printf("Search is Unsuccessful");





    return 0;
}
