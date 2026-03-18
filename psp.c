#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0;
    int at[10],bt[10],rt[10],pr[10],ct[10],tat[10],wt[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(completed<n)
    {
        int index=-1;
        int highest=999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && pr[i]<highest)
            {
                highest=pr[i];
                index=i;
            }
        }

        if(index==-1)
            time++;

        else
        {
            rt[index]--;
            time++;

            if(rt[index]==0)
            {
                completed++;
                ct[index]=time;
                tat[index]=ct[index]-at[index];
                wt[index]=tat[index]-bt[index];
            }
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}
