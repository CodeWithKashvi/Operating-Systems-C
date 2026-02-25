//Shortest Job First Scheduling when Arrival Time = 0.(we used bubble sort to solve the question)

#include<stdio.h>

int main()
{
    int n,i,j,bt[20], wt[20], tat[20], temp;

    printf("enter num of processs:");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i+1 );
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if( bt[j] > bt[j+1] )
            {
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }

wt[0] = 0;
            for(i = 1; i < n; i++)
{
    wt[i] = wt[i-1] + bt[i-1];
}
for(i = 0; i < n; i++) 
{
    tat[i] = wt[i] + bt[i]; 
}
printf("Process\tBT\tWT\tTAT\n");
for(i = 0; i < n; i++)
{
    printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);    
}

}
