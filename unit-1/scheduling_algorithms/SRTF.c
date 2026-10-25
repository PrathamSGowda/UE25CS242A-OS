#include <stdio.h>

int main()
{
    /*
    a[10]    - Arrival time of each process.
    b[10]    - Remaining burst time of each process.
    x[10]    - Original burst time of each process.
    smallest - Index of the process with the smallest remaining
            burst time among the arrived, unfinished processes.
    count    - Number of processes that have completed execution.
    time     - Current time in the CPU scheduling simulation.
    n        - Total number of processes.
    wait     - Total waiting time of all processes.
    tat      - Total turnaround time of all processes.
    end      - Completion time of the process that finishes.
    pn[10][10] - Stores the names of the processes.
    */

    int a[10], b[10], x[10], i, smallest;
    int count = 0, time, n, wait = 0, tat = 0, end;
    char pn[10][10];

    printf("Enter the number of processes to schedule:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the process name, arrival time and burst time for each process:\n");
        scanf("%s %d %d", pn[i], &a[i], &b[i]);

        x[i] = b[i];
    }

    b[9] = 9999;

    printf("Process\tburst-time\tarrival-time\twaiting-time\tturnaround-time\tcompletiontime\n");
    printf("-------\t----------\t------------\t------------\t---------------\t---------------\n");

    for (time = 0; count != n; time++)
    {
        smallest = 9;

        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
            {
                smallest = i;
            }
        }

        if (--b[smallest] == 0)
        {
            count++;
            end = time + 1;

            wait += end - a[smallest] - x[smallest];
            tat += end - a[smallest];

            printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   pn[smallest],
                   x[smallest],
                   a[smallest],
                   end - a[smallest] - x[smallest],
                   end - a[smallest],
                   end);
        }
    }

    printf("\n\nAverage waiting time = %lf\n", (float)wait / n);
    printf("Average Turnaround time = %lf\n", (float)tat / n);

    return 0;
}