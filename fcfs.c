#include <stdio.h>

/*
 * FCFS (First-Come, First-Served) CPU Scheduling Algorithm using user-defined functions
 * This program calculates the waiting time, turnaround time, and average times
 * for a set of processes based on arrival times and burst times.
*/

    void inputData(int n, int arrival[], int burst[]);
    void calculateCompletion(int n, int arrival[], int burst[], int completion[]);
    void calculateTimes(int n, int burst[], int arrival[], int completion[], int waiting[], int turnaround[]);
    void displayResults(int n, int arrival[], int burst[], int completion[], int waiting[], int turnaround[]);

    int main() {
        int n;
        printf("Enter the number of processes: ");
        scanf("%d", &n);

        int arrival[n], burst[n], completion[n];
        int waiting[n], turnaround[n];

        inputData(n, arrival, burst);
        calculateCompletion(n, arrival, burst, completion);
        calculateTimes(n, burst, arrival, completion, waiting, turnaround);
        displayResults(n, arrival, burst, completion, waiting, turnaround);

        return 0;
}

                                            // Function to read arrival and burst times
                                            void inputData(int n, int arrival[], int burst[]) {
                                                for (int i = 0; i < n; i++) {
                                                        printf("Enter arrival time for process P%d: ", i + 1);
                                                                scanf("%d", &arrival[i]);
                                                                        printf("Enter burst time for process P%d: ", i + 1);
                                                                                scanf("%d", &burst[i]);
                                                                                    }
                                                                                    }

                                                                                    // Function to calculate completion times for FCFS
                                                                                    void calculateCompletion(int n, int arrival[], int burst[], int completion[]) {
                                                                                        completion[0] = arrival[0] + burst[0];
                                                                                            for (int i = 1; i < n; i++) {
                                                                                                    if (arrival[i] > completion[i - 1]) {
                                                                                                                completion[i] = arrival[i] + burst[i];
                                                                                                                        } else {
                                                                                                                                    completion[i] = completion[i - 1] + burst[i];
                                                                                                                                            }
                                                                                                                                                }
                                                                                                                                                }

                                                                                                                                                // Function to calculate waiting and turnaround times
                                                                                                                                                void calculateTimes(int n, int burst[], int arrival[], int completion[], int waiting[], int turnaround[]) {
                                                                                                                                                    for (int i = 0; i < n; i++) {
                                                                                                                                                            turnaround[i] = completion[i] - arrival[i];
                                                                                                                                                                    waiting[i] = turnaround[i] - burst[i];
                                                                                                                                                                        }
                                                                                                                                                                        }

                                                                                                                                                                        // Function to display process metrics and averages
                                                                                                                                                                        void displayResults(int n, int arrival[], int burst[], int completion[], int waiting[], int turnaround[]) {
                                                                                                                                                                            printf("\nProcess\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
                                                                                                                                                                                float total_wait = 0, total_turnaround = 0;
                                                                                                                                                                                    for (int i = 0; i < n; i++) {
                                                                                                                                                                                            printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
                                                                                                                                                                                                           i + 1, arrival[i], burst[i], completion[i], waiting[i], turnaround[i]);
                                                                                                                                                                                                                   total_wait += waiting[i];
                                                                                                                                                                                                                           total_turnaround += turnaround[i];
                                                                                                                                                                                                                               }
                                                                                                                                                                                                                                   printf("\nAverage waiting time: %.2f\n", total_wait / n);
                                                                                                                                                                                                                                       printf("Average turnaround time: %.2f\n", total_turnaround / n);
                                                                                                                                                                                                                                       }
