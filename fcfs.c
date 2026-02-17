//First Come First Serve Scheduling 

#include <stdio.h>

int main()
{
    int n, i;
    int at[20], bt[20], wt[20], tat[20], ct[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    
    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Completion Time Calculation
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Turnaround Time and Waiting Time
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
