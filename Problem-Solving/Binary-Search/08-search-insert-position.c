/* LeetCode: Search Insert Position */
int searchInsert(int* nums, int numsSize, int target) {
    int low=0, high=numsSize;
    while (low<high) {
        int mid=low+(high-low)/2;
        if (nums[mid]<target) low=mid+1;
        else high=mid;
    }
    return low;
}
