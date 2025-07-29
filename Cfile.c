#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern void computeAcceleration(float* matrix, int num_cars, int* output);

int main() {
    int Y;
    char answer[100];
    char mode[100];
    char line[256];

    printf("Enter mode (manual/test): ");
    scanf("%s", mode);
    getchar();

    if (strcmp(mode, "test") == 0 || strcmp(mode, "TEST") == 0) {
        int test_sizes[] = {10, 100, 1000, 10000};
        int t, i, trial;
        float* matrix;
        int* output;
        clock_t start, end, total;

        srand((unsigned int)time(NULL));

        for (t = 0; t < 4; t++) {
            Y = test_sizes[t];

            matrix = malloc(sizeof(float) * Y * 3);
            output = malloc(sizeof(int) * Y);

            for (i = 0; i < Y; i++) {
                matrix[i * 3] = (float)(rand() % 201);              
                matrix[i * 3 + 1] = matrix[i * 3] + (rand() % 101); 
                matrix[i * 3 + 2] = (float)((rand() % 90) + 10);    
            }

            total = 0;
            for (trial = 0; trial < 30; trial++) {
                start = clock();
                computeAcceleration(matrix, Y, output);
                end = clock();
                total += (end - start);
            }

            printf("\nY = %d\n", Y);
            printf("Average execution time over 30 trials: %.6f seconds\n", ((double)total / CLOCKS_PER_SEC) / 30.0);

            free(matrix);
            free(output);
        }

        return 0;
    }
 
    int i, scanned;
    float* matrix;
    int* output;

    do {
        printf("Enter number of cars: ");
        scanf("%d", &Y);
        getchar();

        matrix = malloc(sizeof(float) * Y * 3);
        output = malloc(sizeof(int) * Y);

        printf("Enter each row per car:\n");
        printf("Format: InitialVelocity FinalVelocity Time\n");

        for (i = 0; i < Y; i++) {
            do {
                printf("Car %d: ", i + 1);
                if (!fgets(line, sizeof(line), stdin)) {
                    printf("Error reading input.\n");
                    exit(1);
                }

                scanned = sscanf(line, "%f %f %f", &matrix[i * 3], &matrix[i * 3 + 1], &matrix[i * 3 + 2]);
                if (scanned != 3) {
                    printf("Invalid input! Please enter exactly three numbers (InitialVelocity FinalVelocity Time).\n");
                }
            } while (scanned != 3);
        }

        computeAcceleration(matrix, Y, output);

        printf("Acceleration results:\n");
        for (i = 0; i < Y; i++) {
            printf("%d\n", output[i]);
        }

        free(matrix);
        free(output);

        while (1) {
            printf("\nRe-do the program? (yes/no): ");
            scanf("%s", answer);

            if (strcmp(answer, "yes") == 0 || strcmp(answer, "YES") == 0 || strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0 ||
                strcmp(answer, "no") == 0 || strcmp(answer, "NO") == 0 || strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0)
                break;

            printf("Please answer only 'yes' or 'no'.\n");
        }

    } while (strcmp(answer, "yes") == 0 || strcmp(answer, "YES") == 0 || strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0);

    return 0;
}

