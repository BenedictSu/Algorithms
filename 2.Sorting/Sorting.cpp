#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100001

int inputSize, inputs[MAX_N];
// variables for swapCheck
int swapCount, tempLeftSwap, leftSwap, rightSwap;

void swapCheck(int index) {
    // only check for swap there were less than 2 swaps done
    if (swapCount < 2) {
        if (inputs[index] < inputs[index - 1]) {
            leftSwap = index - 1;
            rightSwap = index;
            inputs[index] = inputs[index - 1];
            swapCount++;
        }
    }
}

int main() {
    while (EOF != scanf("%d", &inputSize)) {
        
        int isSorted = 1;
        // reset variables
        swapCount = 0, tempLeftSwap = -1;

        // read in all the inputs into inputs array
        scanf("%d", &inputs[1]);
        for (int i = 2; i <= inputSize; i++) {
            scanf("%d", &inputs[i]);
        }

        // do a simple swap check
        for (int i = 2; i <= inputSize; i++) {
            swapCheck(i);
        }

        if (0 == swapCount) {
            printf("yes\n");
        } else if (1 == swapCount) {
            printf("yes\n");
            printf("swap %d %d\n", leftSwap, rightSwap);
        } else {
            printf("no\n");
        }
    }
    return 0;
}