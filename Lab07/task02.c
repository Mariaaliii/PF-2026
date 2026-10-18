#include <stdio.h>
int main() {
    int a[5][5], b[5][5], p[5][5], c[5][5];
    int n, m, i, j, k;
    int zero = 1, diagonal = 1, identity = 1, scalar = 1;
    int upper = 1, lower = 1, symmetric = 1, skew = 1;
    int idempotent = 1, nilpotent = 0, equal = 1;
    int power, allzero, choice;
    double d[5][5], x, det = 1;

    printf("Enter rows and columns: ");
    scanf("%d%d", &n, &m);

    if (n < 1 || n > 5 || m < 1 || m > 5) {
        printf("Invalid size!\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    printf("\nMatrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] != 0)
                zero = 0;

            if (i != j && a[i][j] != 0)
                diagonal = 0;

            if (i > j && a[i][j] != 0)     
                upper = 0;

            if (i < j && a[i][j] != 0)    
                lower = 0;
        }
    }

    printf("\nMatrix Types:\n");

    if (n == m)
        printf("Square Matrix\n");
    else
        printf("Rectangular Matrix\n");

    if (n == 1)
        printf("Row Matrix\n");

    if (m == 1)
        printf("Column Matrix\n");

    if (zero)
        printf("Zero Matrix\nNull Matrix\n");

    if (n == m) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] != a[j][i])
                    symmetric = 0;

                if (a[i][j] != -a[j][i])
                    skew = 0;

                if (i == j && a[i][i] != 1)
                    identity = 0;

                if (i == j && a[i][i] != a[0][0])
                    scalar = 0;
            }
       }
        
        if (!diagonal)
        {
            scalar = 0;
            identity = 0;
        }

        if (identity)
            printf("Identity Matrix\n");

        if (diagonal)
            printf("Diagonal Matrix\n");

        if (scalar)
            printf("Scalar Matrix\n");

        if (upper)
            printf("Upper Triangular Matrix\n");

        if (lower)
            printf("Lower Triangular Matrix\n");

        if (symmetric)
            printf("Symmetric Matrix\n");

        if (skew)
            printf("Skew-Symmetric Matrix\n");

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                d[i][j] = a[i][j];

        det = 1;

        for (i = 0; i < n; i++)
        {
            if (d[i][i] < 0.000001 && d[i][i] > -0.000001)
            {
                for (k = i + 1; k < n; k++)
                {
                    if (d[k][i] > 0.000001 || d[k][i] < -0.000001)
                    {
                        for (j = 0; j < n; j++)
                        {
                            x = d[i][j];
                            d[i][j] = d[k][j];
                            d[k][j] = x;
                        }

                        det = -det;         
                        break;
                    }
                }
            }

            if (d[i][i] < 0.000001 && d[i][i] > -0.000001)
            {
                det = 0;
                break;
            }

            det = det * d[i][i];

            for (k = i + 1; k < n; k++)
            {
                x = d[k][i] / d[i][i];

                for (j = i; j < n; j++)
                    d[k][j] = d[k][j] - x * d[i][j];
            }
        }

        if (det < 0.000001 && det > -0.000001)
            printf("Singular Matrix\n");
        else
            printf("Non-Singular Matrix\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                b[i][j] = 0;

                for (k = 0; k < n; k++)
                    b[i][j] = b[i][j] + a[i][k] * a[k][j];

                if (b[i][j] != a[i][j])
                    idempotent = 0;
            }
        }

        if (idempotent)
            printf("Idempotent Matrix\n");
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                b[i][j] = a[i][j];          

        for (power = 1; power <= n; power++)
        {
            allzero = 1;

            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    if (b[i][j] != 0)
                        allzero = 0;

            if (allzero)
            {
                nilpotent = 1;
                break;
            }

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    p[i][j] = 0;

                    for (k = 0; k < n; k++)
                        p[i][j] = p[i][j] + b[i][k] * a[k][j];
                }
            }

            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    b[i][j] = p[i][j];
        }

        if (nilpotent)
            printf("Nilpotent Matrix\n");
    }


    printf("\nDo you want to compare with another matrix? (1 = yes, 0 = no): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter a second matrix of size %d x %d:\n", n, m);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &c[i][j]);

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (a[i][j] != c[i][j])
                    equal = 0;

        if (equal)
            printf("Equal Matrix (both matrices are the same)\n");
        else
            printf("The two matrices are NOT equal\n");
    }

    return 0;
}
