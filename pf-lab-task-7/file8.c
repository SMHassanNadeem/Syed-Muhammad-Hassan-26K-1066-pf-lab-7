#include <stdio.h>

int main() 
{
    int stock[3][4][5] = {
        {
            {12, 15, 8, 4, 20},
            {25, 30, 18, 22, 19},
            {6, 7, 3, 11, 14},
            {10, 12, 15, 10, 8}
        },
        {
            {5, 8, 12, 9, 6},
            {40, 45, 38, 50, 42},
            {2, 14, 16, 18, 22},
            {11, 13, 10, 12, 15}
        },
        {
            {20, 22, 24, 21, 23},
            {15, 12, 18, 14, 16},
            {9, 8, 12, 11, 10},
            {4, 6, 8, 12, 1}
        }
    };

    int max_shelf_items = -1;
    int fullest_building = -1;
    int fullest_shelf = -1;

    printf("RESTOCK ALERTS (< 5 items)\n");

    for (int b = 0; b < 3; b++) 
    {
        int building_total = 0;

        for (int s = 0; s < 4; s++) 
        {
            int shelf_total = 0;

            for (int sl = 0; sl < 5; sl++) 
            {
                int items = stock[b][s][sl];
                shelf_total += items;

                if (items < 5) 
                {
                    printf("Alert: Slot [%d][%d][%d] has only %d items -> needs restock\n", b, s, sl, items);
                }
            }

            building_total += shelf_total;

            if (shelf_total > max_shelf_items) 
            {
                max_shelf_items = shelf_total;
                fullest_building = b;
                fullest_shelf = s;
            }
        }

        printf(">> Total stock for Building %d: %d items\n\n",b,building_total);
    }

    printf("LOGISTICS REPORT\n");
    printf("The single fullest shelf is Shelf %d in Building %d (Total items on shelf: %d)\n",fullest_shelf, fullest_building, max_shelf_items);

    return 0;
}
