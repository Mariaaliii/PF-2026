#include<stdio.h>
int main(){
	int a[3][3];
	int i, j;
	int det;
	int c[3][3];
	int adj[3][3];
	printf("Enter Elements: \n");
	for(i = 0; i<3; i++) {
		for(j = 0; j<3; j++) {
		scanf("%d", &a[i][j]);
		}
	}
	printf("\nOriginal Matrix:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
	printf("\nThe Transpose is: \n");
	for(i = 0; i<3; i++) {
		for(j = 0; j<3 ; j++){
			printf("%d\t", a[j][i]);
		}
		printf("\n");
	}
	det = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1]) -  a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2]) +  a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]);
	printf("\nDeterminant of a Matrix is: %d\n", det);
    
	c[0][0]= a[1][1]*a[2][2]-a[1][2]*a[2][1];
    c[0][1]=-(a[1][0]*a[2][2]-a[1][2]*a[2][0]);
    c[0][2]= a[1][0]*a[2][1]-a[1][1]*a[2][0];

    c[1][0]=-(a[0][1]*a[2][2]-a[0][2]*a[2][1]);
    c[1][1]= a[0][0]*a[2][2]-a[0][2]*a[2][0];
    c[1][2]=-(a[0][0]*a[2][1]-a[0][1]*a[2][0]);

    c[2][0]= a[0][1]*a[1][2]-a[0][2]*a[1][1];
    c[2][1]=-(a[0][0]*a[1][2]-a[0][2]*a[1][0]);
    c[2][2]= a[0][0]*a[1][1]-a[0][1]*a[1][0];

    printf("\nCofactor of Matrix is:\n");
    for(i = 0; i<3; i++) {
        for(j = 0; j<3; j++) {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    
	for(i = 0; i<3; i++) {
        for(j = 0; j<3; j++) {
            adj[j][i]=c[i][j];
       }
    }
    printf("\nAdjoint of  Matrix is:\n");
    for(i = 0; i<3; i++) { 
        for(j = 0; j<3; j++) {
            printf("%d\t",adj[i][j]);
        }
		printf("\n");
    }

    if(det == 0) {
        printf("\nInverse does not exist.\n");
    } 
	else {
        printf("\nInverse of Matrix is:\n");
        for(i = 0; i<3; i++) {
            for(j = 0; j<3; j++) {
                printf("%d\t", adj[i][j]/det);
            }
			printf("\n");
        }
    }
	return 0;
}
