#include <stdio.h>
int main()
{
    int marks[3][4][5] = {
        {{85, 90, 78, 92, 88},
         {45, 38, 70, 65, 80},
         {70, 72, 68, 74, 71},
         {95, 92, 89, 96, 94}},
        {{60, 65, 70, 62, 68},
         {88, 85, 90, 87, 89},
         {55, 58, 62, 50, 57},
         {75, 78, 80, 77, 79}},
        {{90, 91, 88, 93, 89},
         {78, 82, 80, 85, 81},
         {65, 68, 72, 70, 69},
         {82, 80, 85, 88, 84}}};

    int dept_total_sum[3] = {0.0, 0.0, 0.0};
    int dept_topper_id[3];
    float dept_topper_avg[3] = {-1.0, -1.0, -1.0};

    for (int i = 0; i < 3; i++)
    {
        printf("Department %d :", i);
        for (int j = 0; j < 4; j++)
        {
            int sum = 0;
            int failed = 0;
            for (int k = 0; k < 5; k++)
            {
                int current_mark = marks[i][j][k];
                sum += current_mark;

                if (current_mark < 40)
                {
                    failed = 1;
                }

                double avg = sum / 5.0;
                dept_total_sum[j] += avg;

                if (failed)
                {
                    printf("  Student %d: Avg = %.2f | Status: [FAIL] (Subject mark under 40)\n", i, avg);
                }
                else
                {
                    printf("  Student %d: Avg = %.2f | Status: PASSED\n", i, avg);
                }

                if (avg > dept_topper_avg[j])
                {
                    dept_topper_avg[j] = avg;
                    dept_topper_id[j] = i;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) 
    {
        printf("Department %d Topper: Student %d (Avg: %.2f)\n", i, dept_topper_id[i], dept_topper_avg[i]);
    }

    int best_dept = 0;
    double highest_dept_avg = -1.0;

    for (int d = 0; d < 3; d++) 
    {
        double current_dept_avg = dept_total_sum[d] / 4.0; 
        printf("Department %d Overall Average: %.2f\n", d, current_dept_avg);

        if (current_dept_avg > highest_dept_avg) 
        {
            highest_dept_avg = current_dept_avg;
            best_dept = d;
        }
    }

    printf("\n>> Department with the highest overall average: Department %d (Avg: %.2f) <<\n", best_dept, highest_dept_avg);
}