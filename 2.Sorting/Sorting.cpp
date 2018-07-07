#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100001

int inputSize, inputs[MAX_N];
// variables for swapCheck
int swapCount, leftSwap, rightSwap;

void swap() {
    int swapHolder = inputs[rightSwap];
    inputs[rightSwap] = inputs[leftSwap];
    inputs[leftSwap] = swapHolder;
    swapCount++;
}

void postSwapCheck() {
    // check that the swap result in a valid ascending order
    if (inputs[rightSwap] < inputs[rightSwap - 1]) {
        // can no longer have ascending order with this swap
        swapCount++;
    } else if (inputs[leftSwap] > inputs[leftSwap + 1]) {
        // can no longer have ascending order with this swap
        swapCount++;
    } else if (1 != leftSwap && inputs[leftSwap] < inputs[leftSwap - 1]) {
        // can no longer have ascending order with this swap
        swapCount++;
    }
}

void swapCheck() {
    for (int i = 2; i <= inputSize; i++) {
        // only check for swap if there was less than 2 swaps done
        if (swapCount < 2) {
            if (inputs[i] < inputs[i - 1]) {
                // this input is smaller than the previous input
                if (0 == swapCount) {
                    if (-1 == leftSwap) {
                        // set the swap in as pending
                        leftSwap = i - 1;
                        rightSwap = i;
                    } else {
                        rightSwap = i;
                        // commit the swap
                        swap();
                        postSwapCheck();
                    }
                } else {
                    // already have 1 swap done
                    swapCount++;
                }
            }
        }
    }
}

int main() {
    while (EOF != scanf("%d", &inputSize)) {
        
        int isSorted = 1;
        // reset variables
        swapCount = 0, leftSwap = -1;

        // read in all the inputs into inputs array
        scanf("%d", &inputs[1]);
        for (int i = 2; i <= inputSize; i++) {
            scanf("%d", &inputs[i]);
        }

        // do a swap check
        swapCheck();
        if (0 == swapCount && -1 != leftSwap) {
            // commit the pending swap
            swap();
            postSwapCheck();
            // Extra check for right side
            if (inputSize != rightSwap && inputs[rightSwap] > inputs[rightSwap + 1]) {
                // can no longer have ascending order with this swap
                swapCount++;
            }
        }
        if (swapCount > 1) {
            // undo the swap for the reverse check
            int swapHolder = inputs[rightSwap];
            inputs[rightSwap] = inputs[leftSwap];
            inputs[leftSwap] = swapHolder;
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