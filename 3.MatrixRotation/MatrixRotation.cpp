#include <bits/stdc++.h>

using namespace std;

#define MAX_N 301

int main() {
    int row, col, rotation;
    int inputs[MAX_N][MAX_N];
    while (EOF != scanf("%d %d %d", &row, &col, &rotation)) {
        // read inputs
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                scanf("%d", &inputs[i][j]);
            }
        }

        // print results
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                 printf("%d", inputs[i][j]);
                 if (j != col) {
                    printf(" ");
                 }
            }
            printf("\n");
        }
    }
    return 0;
}