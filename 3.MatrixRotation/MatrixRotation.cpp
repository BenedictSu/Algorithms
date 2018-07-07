#include <bits/stdc++.h>

using namespace std;

#define MAX_N 301

int row, col, rotation;
int inputs[MAX_N][MAX_N];
int outputs[MAX_N][MAX_N];

int determineOutput(int standardiseRotation, int numElements, int x1, int x2, int y1, int y2) {
    // remove complete circles to consider only how much to rotate within 1 circle
    int innerRotation = standardiseRotation % numElements;
    int numRow = x2 - x1;
    int numCol = y2 - y1;
    if (innerRotation <= numRow) {
        // go down left most col
        return inputs[x1][y1 + innerRotation];
    } else if (innerRotation <= numRow + numCol) {
        // go right on bottow most row
        return inputs[x1 + innerRotation - numRow][y2];
    } else if (innerRotation <= 2 * numRow + numCol) {
        // go up right most col
        return inputs[x2][y2 - (innerRotation - numRow - numCol)];
    } else {
        // go left on bottow most row
        return inputs[x2 - (innerRotation - 2 * numRow - numCol)][y1];
    }
}


void rotateMatrix() {
    // number of 'rotating circles' = row/2
    for (int i = 0; i < row / 2; i++) {
        // determine corner coordinates for this circle
        int x1 = 1 + i;
        int x2 = col - i;
        int y1 = 1 + i;
        int y2 = row - i;
        int numElements = (2 * (x2 - x1)) + (2 * (y2 - y1));

        // top and bottom rows
        for (int x_coor = x1; x_coor <= x2; x_coor++) {
            // standardise the coordinate to x1, y1 by adding to rotation required
            int standardiseRotation = rotation + (numElements - (x_coor - x1));
            // top row
            outputs[x_coor][y1] = determineOutput(standardiseRotation, numElements, x1, x2, y1, y2);

            // bottom row
            standardiseRotation = rotation + (numElements + (y2 - y1) + (x_coor - x1));
            outputs[x_coor][y2] = determineOutput(standardiseRotation, numElements, x1, x2, y1, y2);
        }

        // left and right col, skip first and last elements calculated
        for (int y_coor = y1 + 1; y_coor < y2; y_coor++) {
            // standardise the coordinate to x1, y1 by adding to rotation required
            int standardiseRotation = rotation + (y_coor - y1);
            // left col
            outputs[x1][y_coor] = determineOutput(standardiseRotation, numElements, x1, x2, y1, y2);

            // right col
            standardiseRotation = rotation + (numElements - (x2 - x1) - (y_coor - y1));
            outputs[x2][y_coor] = determineOutput(standardiseRotation, numElements, x1, x2, y1, y2);
        }
    }
}

int main() {
    while (EOF != scanf("%d %d %d", &row, &col, &rotation)) {
        // read inputs
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                scanf("%d", &inputs[i][j]);
            }
        }

        rotateMatrix();

        // print results
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                 printf("%d", outputs[i][j]);
                 if (j != col) {
                    printf(" ");
                 }
            }
            printf("\n");
        }
    }
    return 0;
}