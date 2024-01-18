## Q2 - Write a C program to simulate the following CPU scheduling algorithm: *Shortest Job First [SJF]*

### C program - **algoSJF.c**
```
#include<stdio.h>

void sjfScheduling(int bt[], int p[], int wt[], int tat[], int n) {
    int pos, temp, total = 0;
    float avgWt, avgTat;

    //sorting based on burstTime
    for (int i = 0; i < n; ++i) {
        pos = i;
        for (int j = i + 1; j < n; ++j) {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (int i = 1; i < n; ++i) {
        wt[i] = 0;
        for (int j = 0; j < i; ++j)
            wt[i] += bt[j];
        total += wt[i];
    }

    avgWt = (float)total / n;
    total = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; ++i) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avgTat = (float)total / n;
    printf("\n\nAverage Waiting Time = %f", avgWt);
    printf("\nAverage Turnaround Time = %f\n", avgTat);
}

int main() {
    int burstTime[20], process[20], waitTime[20], turnAroundTime[20], n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (int i = 0; i < n; ++i) {
        printf("P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1;
    }

    sjfScheduling(burstTime, process, waitTime, turnAroundTime, n);

    return 49;
}
```

### Command to compile the C program
```
gcc -o algoSJF algoSJF.c
```

### Command to run the program
```
./algoSJF 
```


