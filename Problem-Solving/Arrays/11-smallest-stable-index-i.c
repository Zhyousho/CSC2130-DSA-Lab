/* LeetCode: Smallest Stable Index I */
int firstStableIndex(int* nums, int numsSize, int k) {
    for (int i=0; i<numsSize; i++) {
        int max=nums[0], min=nums[i];
        for (int j=1; j<=i; j++)
            if (nums[j]>max) max=nums[j];
        for (int j=i; j<numsSize; j++)
            if (nums[j]<min) min=nums[j];
        if (max-min<=k) return i;
    }
    return -1;
}
