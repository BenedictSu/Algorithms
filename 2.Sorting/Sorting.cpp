#include <bits/stdc++.h>

using namespace std;

int main() {
    int inputSize;
    while (EOF != scanf("%d", &inputSize)) {
        int previousInput, currentInput;
        int isSorted = 1;
        // init with the first number
        scanf("%d", &previousInput);
        for (int i = 1; i < inputSize; i++) {
            scanf("%d", &currentInput);
            if (currentInput < previousInput) {
                isSorted = 0;
            }
            previousInput = currentInput;
        }
        if (isSorted) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}