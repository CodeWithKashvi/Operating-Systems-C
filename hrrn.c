#include <stdio.h>

int main()
{
    int n,i,j,time=0,completed=0;
    int at[20],bt[20],ct[20],tat[20],wt[20],done[20]={0};
    float rr,max_rr;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(completed<n)
    {
        max_rr=-1;
        int index=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0)
            {
                rr=(time-at[i]+bt[i])/(float)bt[i];
                if(rr>max_rr)
                {
                    max_rr=rr;
                    index=i;
                }
            }
        }

        if(index==-1)
            time++;
        else
        {
            ct[index]=time+bt[index];
            time=ct[index];
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];
            done[index]=1;
            completed++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
