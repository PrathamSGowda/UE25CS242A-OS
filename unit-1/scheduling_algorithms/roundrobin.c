// This implementation of round robin does not use a queue :/

#include <stdio.h>

void main()
{
    /*
    NOP     - Total number of processes.
    sum     - Total elapsed CPU time.
    count   - Flag used to indicate process completion.
    y       - Number of processes remaining to be completed.
    quant   - Time quantum allocated to each process.
    wt      - Total waiting time of all processes.
    tat     - Total turnaround time of all processes.
    at[10]  - Arrival time of each process.
    bt[10]  - Original burst time of each process.
    temp[10]- Remaining burst time of each process.
    avg_wt  - Average waiting time of all processes.
    avg_tat - Average turnaround time of all processes.
    */

    int i, NOP, sum = 0, count = 0, y, quant;
    int wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Enter the total number of process to schedule: ");
    scanf("%d", &NOP);

    y = NOP;

    for (i = 0; i < NOP; i++)
    {
        printf("\nEnter the Arrival and Burst time of the Process[%d]: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        temp[i] = bt[i];
    }

    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No\t\tBurst Time\t\tTAT\t\tWaiting Time ");

    for (sum = 0, i = 0; y != 0; )
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        if (temp[i] == 0 && count == 1)
        {
            y--;

            printf("\nProcess No[%d]\t\t%d\t\t\t%d\t\t\t%d",
                   i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);

            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];

            count = 0;
        }

        if (i == NOP - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_tat = (float)tat / NOP;
    avg_wt = (float)wt / NOP;

    printf("\nAverage Turn Around Time: %f", avg_tat);
    printf("\nAverage Waiting Time: %f\n", avg_wt);
}