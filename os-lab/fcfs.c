#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int i, time = 0;

    for(i = 0; i < n; i++)
        p[i] = i + 1;

    printf("Enter Arrival Time of each process:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Time of each process:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // FCFS executes in arrival order (assuming ATs are given in sorted order)
    for(i = 0; i < n; i++) {
        if(time < at[i])        // CPU is idle until process arrives
            time = at[i];
        time += bt[i];
        ct[i] = time;
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);

    float avgWT = 0, avgTAT = 0;
    for(i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time = %.2f\n", avgWT);
    printf("Average Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

