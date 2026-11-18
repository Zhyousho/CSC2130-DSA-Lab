#include <stdlib.h>
/* LeetCode: Find First and Last Position of Element in Sorted Array */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* result=malloc(2*sizeof(int));
    if (!result) { *returnSize=0; return NULL; }
    result[0]=result[1]=-1;
    int low=0, high=numsSize-1, mid;
    while (low<=high) {
        mid=low+(high-low)/2;
        if (nums[mid]>=target) high=mid-1;
        else low=mid+1;
    }
    if (low<numsSize && nums[low]==target) result[0]=low;
    low=0; high=numsSize-1;
    while (low<=high) {
        mid=low+(high-low)/2;
        if (nums[mid]<=target) low=mid+1;
        else high=mid-1;
    }
    if (high>=0 && nums[high]==target) result[1]=high;
    return result;
}
