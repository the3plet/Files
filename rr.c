#include <stdio.h>
void main()
{
    int i, j, n, bu[10], temp = 0, wa[10], tat[10], ct[10], max, t, total_tat, tot_wat;

    printf("enter the no of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the burst time for process %d : ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];
    }
    printf("enter the time slice : ");
    scanf("%d", &t);
    max = bu[0];
    for (i = 1; i < n; i++)
    {
        if (max < bu[i])

            max = bu[i];
    }

    for (j = 0; j < (max / t) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {

            if (bu[i] != 0)
                if (bu[i] <= t)
                {
                    tat[i] = temp + bu[i];
                    temp = temp + bu[i];
                    bu[i] = 0;
                }
                else
                {
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }
        }
    }

    for (i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];
        total_tat += tat[i];
        tot_wat += wa[i];
    }
    printf("\n the average waiting around time is --%f", (float)tot_wat / n);
    printf("\n the average turn around time is --%f", (float)total_tat / n);
    printf("\n \t process\t burst_time \t waiting_time \t turnaround_time \n");
    for (i = 0; i < n; i++)
    {
        printf("\t %d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
    }
}