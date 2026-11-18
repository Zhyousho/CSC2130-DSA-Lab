#include <stdlib.h>
/* LeetCode: Two Sum */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* arr = malloc(2 * sizeof(int));
    if (!arr) { *returnSize = 0; return NULL; }
    for (int i=0; i<numsSize; i++) {
        for (int j=0; j<numsSize && j!=i; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i; arr[1] = j;
                return arr;
            }
        }
    }
    free(arr);
    *returnSize = 0;
    return NULL;
}
