/* LeetCode: House Robber */
int rob(int* nums, int numsSize) {
    int prev1=0, prev2=0;
    for (int i=0; i<numsSize; i++) {
        int current=prev1;
        if (nums[i]+prev2>current) current=nums[i]+prev2;
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}
