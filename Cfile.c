#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void computeAcceleration(float* matrix, int num_cars, int* output);

int main() 
{
    int Y;
    char answer[100];
    char line[256];

    do{
        printf("Enter number of cars: ");
        scanf("%d", &Y);
        getchar();

        float* matrix = malloc(sizeof(float) * Y * 3);
        int* output = malloc(sizeof(int) * Y);

        printf("Enter each row per car:\n");
        printf("Format: InitialVelocity FinalVelocity Time\n");
        for (int i = 0; i < Y; i++) 
        {
            int scanned;
            do 
            {
                printf("Car %d: ", i+1);
                if (!fgets(line, sizeof(line), stdin)) 
                {
                    printf("Error reading input.\n");
                    exit(1);
                }
                
                scanned = sscanf(line, "%f %f %f", &matrix[i*3], &matrix[i*3+1], &matrix[i*3+2]);
                if (scanned != 3) 
                {
                    printf("Invalid input! Please enter exactly three numbers (InitialVelocity FinalVelocity Time).\n");
                }
            } while (scanned != 3);
        }

        computeAcceleration(matrix, Y, output);

        printf("Acceleration results:\n");
        for (int i = 0; i < Y; i++) 
        {
            printf("%d\n", output[i]);
        }

        free(matrix);
        free(output);

        while(1)
        {
            printf("\nRe-do the program? (yes/no): ");
            scanf("%s", answer);

            if(strcmp(answer, "yes") == 0 || strcmp(answer, "YES") == 0 || strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0 ||
                strcmp(answer, "no") == 0 || strcmp(answer, "NO") == 0 || strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0)
                break;
            
            printf("Please answer only 'yes' or 'no'.");
        }
        
    } while(strcmp(answer, "yes") == 0 || strcmp(answer, "YES") == 0 || strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0);

    return 0;
}
