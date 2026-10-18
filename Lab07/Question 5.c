#include <stdio.h>
int main(){
    int arr[3][3][3];
    int i, j, k, same;

    printf("Enter elements:\n");
    for(i = 0; i < 3; i++) {
        printf("\nEnter Layer %d:\n", i + 1);
        for(j = 0; j < 3; j++) {
            for(k = 0; k < 3; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\nEntered Layers:\n");

    for(i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);

        for(j = 0; j < 3; j++) {
            for(k = 0; k < 3; k++) {
                printf("%d\t", arr[i][j][k]);
            }
            printf("\n");
        }
    }
    same = 1;

    for(j = 0; j < 3; j++) {
        for(k = 0; k < 3; k++) {
            if(arr[0][j][k] != arr[1][j][k])
                same = 0;
        }
    }
    if(same == 1) {
        printf("\nLayer 1 and Layer 2 are identical.\n");
    } else {
        printf("\nLayer 1 and Layer 2 are distinct.\n");
    }
    same = 1;

    for(j = 0; j < 3; j++) {
        for(k = 0; k < 3; k++) {
            if(arr[0][j][k] != arr[2][j][k])
                same = 0;
        }
    }
    if(same == 1) {
        printf("Layer 1 and Layer 3 are identical.\n");
    } else {
        printf("Layer 1 and Layer 3 are distinct.\n");
    }
    same = 1;

    for(j = 0; j < 3; j++) {
        for(k = 0; k < 3; k++) {
            if(arr[1][j][k] != arr[2][j][k])
                same = 0;
       }
    }
    if(same == 1) {
        printf("Layer 2 and Layer 3 are identical.\n");
    }
	else {
        printf("Layer 2 and Layer 3 are distinct.\n");
    }
    return 0;
}

