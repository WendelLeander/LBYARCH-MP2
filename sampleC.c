#include <stdio.h>
#include <stdlib.h>


void computeAcceleration(float* matrix, int num_cars, int* output);

int main() 
{
    int Y;
    printf("Enter number of cars: ");
    scanf("%d", &Y);

    float* matrix = malloc(sizeof(float) * Y * 3);
    int* output = malloc(sizeof(int) * Y);

    printf("Enter each row per car:\n");
    printf("Format: InitialVelocity FinalVelocity Time\n");
    for (int i = 0; i < Y; i++) 
    {
        printf("Car %d: ", i+1);
        scanf("%f %f %f", &matrix[i*3], &matrix[i*3+1], &matrix[i*3+2]);
    }

    computeAcceleration(matrix, Y, output);

    printf("Acceleration results:\n");
    for (int i = 0; i < Y; i++) 
    {
        printf("%d\n", output[i]);
    }

    free(matrix);
    free(output);
    
    return 0;
}
