#include <stdio.h>

int main() {
    int seats[5][8];
    int total_free = 0;

    printf("Enter the seating status (0 for empty, 1 for booked):\n");
    for (int i = 0; i < 5; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < 8; j++) {
            scanf("%d", &seats[i][j]);
        }
    }

    printf("\n Seating Map \n");
    for (int i = 0; i < 5; i++) {    
        for (int j = 0; j < 8; j++) {
            if (seats[i][j] == 0) {
                printf(". ");
                total_free++;
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\nTotal free seats in the hall: %d\n", total_free);

    return 0;
}
