#include <stdio.h>
#include <string.h>

void main()
{
    /*
    et[20]  - Execution time (burst time) of each process.
    at[10]  - Arrival time of each process.
    n       - Total number of processes.
    temp    - Temporary integer variable used for swapping arrival
            and execution times.
    st[10]  - Start time of each process.
    ft[10]  - Finish time (completion time) of each process.
    wt[10]  - Waiting time of each process.
    ta[10]  - Turnaround time of each process.
    totwt   - Total waiting time of all processes.
    totta   - Total turnaround time of all processes.
    pn[10][10] - Stores the names of the processes.
    t[10]   - Temporary character array used to swap process names
            while sorting.
    */

    int et[20], at[10], n, i, j, temp;
    int st[10], ft[10], wt[10], ta[10];
    int totwt = 0, totta = 0;
    char pn[10][10], t[10];

    printf("Enter the number of processes to schedule: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the process name, arrival time and execution time of each process: ");
        scanf("%s %d %d", pn[i], &at[i], &et[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (et[i] > et[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = et[i];
                et[i] = et[j];
                et[j] = temp;

                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    }

    printf("\nProcess\tArrivalTime\tExecutionTime\tWaitingTime\tTurnAroundTime");
    printf("\n-------\t-----------\t-------------\t-----------\t--------------");

    for (i = 0; i < n; i++)
    {
        st[i] = (i == 0)
                    ? at[i]
                    : (ft[i - 1] > at[i] ? ft[i - 1] : at[i]);

        wt[i] = st[i] - at[i];
        ft[i] = st[i] + et[i];
        ta[i] = ft[i] - at[i];

        totwt += wt[i];
        totta += ta[i];

        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",
               pn[i], at[i], et[i], wt[i], ta[i]);
    }

    printf("\nAverage waiting time is: %f", (float)totwt / n);
    printf("\nAverage turnaround time is: %f\n", (float)totta / n);
}