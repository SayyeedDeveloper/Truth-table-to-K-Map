#include <stdio.h>
#include <math.h>

void generateTruthTable(int variables, int truthTable[]) {
    int rows = pow(2, variables);
    printf("Truth Table:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = variables - 1; j >= 0; j--) {
            printf("%d", (i >> j) & 1);
            if (j > 0) printf(" ");
        }
        printf(" | %d\n", truthTable[i]);
    }
}

int grayCode(int n) {
    return n ^ (n >> 1);
}

void displayKMapGrid(int variables, int truthTable[]) {
    if (variables > 4) {
        printf("K-Map for more than 4 variables is not supported.\n");
        return;
    }

    int rows = (variables > 2) ? pow(2, variables / 2) : 1;
    int cols = pow(2, variables) / rows;

    printf("\nK-Map:\n");
    printf("      ");
    for (int j = 0; j < cols; j++) {
        int colGray = grayCode(j);
        printf(" %02d ", colGray);
    }
    printf("\n      ");
    for (int j = 0; j < cols; j++) {
        printf("----");
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        int rowGray = grayCode(i);
        printf(" %02d | ", rowGray);
        for (int j = 0; j < cols; j++) {
            int colGray = grayCode(j);
            int index = (rowGray << (variables / 2)) | colGray;
            printf(" %d  ", truthTable[index]);
        }
        printf("\n");
    }
}

int main() {
    int variables;
    printf("Enter the number of variables (up to 4): ");
    scanf("%d", &variables);

    if (variables < 1 || variables > 4) {
        printf("Number of variables should be between 1 and 4.\n");
        return 1;
    }

    int rows = pow(2, variables);
    int truthTable[rows];

    printf("Enter the output values for the truth table (0 or 1):\n");
    for (int i = 0; i < rows; i++) {
        printf("Output for row %d: ", i);
        scanf("%d", &truthTable[i]);
    }

    generateTruthTable(variables, truthTable);
    displayKMapGrid(variables, truthTable);

    return 0;
}