// Shortest Remaining Time First Scheduling 

#include <stdio.h>

int main()
{
    int i,j,n, at[20], bt[20], rt[20], ct[20], wt[20], tat[20];
    int time = 0, completed = 0, min, pos;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Arrival time of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        rt[i] = bt[i];   
    }

    while(completed != n)
    {
        min = 9999;
        pos = -1;

        for(i=0;i<n;i++)
        {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                pos = i;
            }
        }

        if(pos == -1)
        {
            time++;
            continue;
        }

        rt[pos]--;
        time++;

        if(rt[pos] == 0)
        {
            completed++;
            ct[pos] = time;
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];

            avg_wt += wt[pos];
            avg_tat += tat[pos];
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);

    return 0;
}
