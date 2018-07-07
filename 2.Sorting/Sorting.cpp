#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100001

int inputSize, inputs[MAX_N];

// temp data
string execution;
int executionCount, leftIndex, rightIndex;

void resetTempData() {
    execution = "swap";
    executionCount = 0, leftIndex = -1, rightIndex = -1;
}

void simulateExecution() {
    int tempHolder = inputs[rightIndex];
    inputs[rightIndex] = inputs[leftIndex];
    inputs[leftIndex] = tempHolder;
    executionCount++;
}

void postSimulatedExecutionCheck(bool isSwap) {
    // check that the simulated execution result in a valid ascending order

    if (1 != leftIndex && inputs[leftIndex] < inputs[leftIndex - 1]) {
        // can no longer have ascending order with this simulated execution
        executionCount++;
    }

    if (isSwap) {
        // for swap, need to check the item before rightIndex
        // and the item after leftIndex
        if (inputs[rightIndex] < inputs[rightIndex - 1]) {
            // can no longer have ascending order with this simulated execution
            executionCount++;
        } else if (inputs[leftIndex] > inputs[leftIndex + 1]) {
            // can no longer have ascending order with this simulated execution
            executionCount++;
        }
    }
}

void swapCheck() {
    for (int i = 2; i <= inputSize; i++) {
        if (executionCount < 2) {
            // only check for swap if there were less than 2 swaps done
            if (inputs[i] < inputs[i - 1]) {
                // this input is smaller than the previous input, need swap
                if (0 == executionCount) {
                    if (-1 == leftIndex) {
                        // set the swap in as pending
                        leftIndex = i - 1;
                        rightIndex = i;
                    } else {
                        rightIndex = i;
                        // commit the swap
                        simulateExecution();
                        postSimulatedExecutionCheck(true);
                    }
                } else {
                    // already have 1 swap done, cannot swap again
                    executionCount++;
                }
            }
        } else {
            break;
        }
    }
}

void reverseCheck() {
    for (int i = 2; i <= inputSize; i++) {
        if (executionCount < 2) {
            // only check for reverse if there were less than 2 reverses done
            if (inputs[i] < inputs[i - 1]) {
                // this input is smaller than the previous input, need reverse
                if (0 == executionCount) {
                    if (-1 == leftIndex) {
                        // set the reverse in as pending
                        leftIndex = i - 1;
                        rightIndex = i;
                    } 
                } else if (1 == executionCount) {
                    // already have 1 reverse done, cannot reverse again
                    executionCount++;
                }
            } else {
                if (0 == executionCount && -1 != leftIndex) {
                    rightIndex = i - 1;
                    // commit the reverse
                    simulateExecution();
                    postSimulatedExecutionCheck(false);
                    // Extra check for right side
                    if (inputs[rightIndex] > inputs[rightIndex + 1]) {
                        // can no longer have ascending order with this reverse
                        executionCount++;
                    }
                }
            }
        } else {
            break;
        }
    }
}

void postSimulationCheck(bool isSwap) {
    if (0 == executionCount && -1 != leftIndex) {
        // commit the pending simulated execution
        simulateExecution();
        postSimulatedExecutionCheck(isSwap);
        // Extra check for right side
        if (inputSize != rightIndex && inputs[rightIndex] > inputs[rightIndex + 1]) {
            // can no longer have ascending order with this simulateExecution
            executionCount++;
        }
    }
}

int main() {
    while (EOF != scanf("%d", &inputSize)) {
        // read in all the inputs into inputs array
        for (int i = 1; i <= inputSize; i++) {
            scanf("%d", &inputs[i]);
        }

        // do a swap check
        resetTempData();
        swapCheck();
        postSimulationCheck(true);

        if (executionCount > 1) {
            // undo the swap for the reverse check
            int tempHolder = inputs[rightIndex];
            inputs[rightIndex] = inputs[leftIndex];
            inputs[leftIndex] = tempHolder;
        }

        // do a reverse check if not already ordered or cannot order with 1 swap
        if (executionCount > 1) {
            resetTempData();
            reverseCheck();

            if (rightIndex == leftIndex + 1) {
                // the inputs after the rightIndex was determined were descending,
                // set the last input as the rightIndex
                rightIndex = inputSize;
            }

            postSimulationCheck(false);
            if (1 == executionCount) {
                // a reverse was successful
                execution = "reverse";
            }
        }

        if (0 == executionCount) {
            printf("yes\n");
        } else if (1 == executionCount) {
            printf("yes\n");
            printf("%s %d %d\n", execution.c_str(), leftIndex, rightIndex);
        } else {
            printf("no\n");
        }
    }
    return 0;
}