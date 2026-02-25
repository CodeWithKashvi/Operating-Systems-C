// Round Robin Scheduling

#include <stdio.h>

int main()
{
    int i,n,tq;
    int at[20], bt[20], rt[20], ct[20], wt[20], tat[20];
    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Arrival time and Burst time of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(completed != n)
    {
        int executed = 0;

        for(i=0;i<n;i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                executed = 1;

                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        if(executed == 0)
            time++; 
    }

    float avgwt = 0, avgtat = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f", avgtat/n);

    return 0;
}
