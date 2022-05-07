#include<stdio.h>
int main()
{
    float start,max=0,min,idle=0;
    int i,j,k=0,pos,n;
    float av1=0,av2=0;

    printf("Enter number of process\n");
    scanf("%d",&n);

    float at[n],at2[n],bt[n],ex[n],seq[n],re[n],wt[n],tat[n];
    printf("Enter arrival time for processes\n");
    for(i=0;i<n;i++)
    {
     scanf("%f",&at[i]);
     at2[i]=at[i];
    }

    printf("Enter burst time for processes\n");
    for(i=0;i<n;i++)
    {
     scanf("%f",&bt[i]);
    }

    start=at[0];
    for(i=1;i<n;i++)
    {
      if(start>at[i])
       {
       start=at[i];
       }
    }

    printf("Sequence of execution is\n");
    for(i=0;i<n;i++)
    {
    if(max<at[i])
     {
      max=at[i];
     }
    }

    max=max+1;
        for(i=0;i<n;i++,k++){
            min=max;
            for(j=0;j<n;j++){
                if(at[j]!=-1)
                    {
                    if(at[j]<min)
                        {
                            min=at[j];
                            pos=j;
                        }
                    }
            }
      printf("[P%d]  ",pos);

      seq[k]=pos;
      if(start<at[pos]){
         start=at[pos];
         start+=bt[pos];
         at[pos]=-1;
         ex[pos]=start;
      }
      else{
        start+=bt[pos];
        at[pos]=-1;
        ex[pos]=start;
       }
     }

    printf("\n");
    for(i=0;i<n;i++)
    {
       tat[i]=ex[i]-at2[i];
       wt[i]=tat[i]-bt[i];
    }
 printf("\n\nProcess\tArrival-time(s)\t Burst-time(s)\tWaiting-time(s)\n");
   for(i=0;i<n;i++)
    {
      printf("P%d\t\t%.1f\t\t%.1f\t\t%.1f\n",i,at2[i],bt[i],wt[i]);
    }
   for(i=0;i<n;i++)
   {
    av2+=wt[i];
   }
  printf("\n\nAverage waiting time(s) %.2f\n",av2/n);
}


