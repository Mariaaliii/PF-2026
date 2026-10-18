#include <stdio.h>
int main(){
    int arr[3][3][3];
    int i, j, k;
    int total, sum = 0;
    int largest, smallest;

    printf("Enter elements of 3D array:\n");
    for(i = 0; i < 3; i++) {
        printf("\nEnter elements for Layer %d:\n", i + 1);
        for(j = 0; j < 3; j++) {
            for(k = 0; k < 3; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    largest = arr[0][0][0];
    smallest = arr[0][0][0];

    printf("\n3D Array Layers:\n");

    for(i = 0; i < 3; i++) {
        total = 0;

        printf("\nLayer %d:\n", i + 1);

        for(j = 0; j < 3; j++) {
            for(k = 0; k < 3; k++) {
                printf("%d\t", arr[i][j][k]);

                total += arr[i][j][k];
                sum += arr[i][j][k];

                if(arr[i][j][k] > largest)
                    largest = arr[i][j][k];

                if(arr[i][j][k] < smallest)
                    smallest = arr[i][j][k];
            }
            printf("\n");
        }
        printf("Total of Layer %d = %d\n", i + 1, total);
    }
    printf("\n====OVERALL DATA INSIGHTS====");
    printf("\nOverall Total = %d\n", sum);
    printf("Largest Element = %d\n", largest);
    printf("Smallest Element = %d\n", smallest);
    printf("Average = %.2f\n", sum / 27.0);

    return 0;
}
