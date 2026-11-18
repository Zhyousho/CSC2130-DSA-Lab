#include <stdlib.h>
/* LeetCode: 3Sum */
static int compareInt(const void *a, const void *b) {
    int x=*(const int*)a, y=*(const int*)b;
    return (x>y)-(x<y);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compareInt);
    int capacity=16, count=0;
    int** result=malloc(capacity*sizeof(int*));
    if (!result) { *returnSize=0; *returnColumnSizes=NULL; return NULL; }
    for (int i=0; i<numsSize-2; i++) {
        if (i>0 && nums[i]==nums[i-1]) continue;
        int left=i+1, right=numsSize-1;
        while (left<right) {
            long sum=(long)nums[i]+nums[left]+nums[right];
            if (sum<0) left++;
            else if (sum>0) right--;
            else {
                if (count==capacity) {
                    capacity*=2;
                    int** grown=realloc(result, capacity*sizeof(int*));
                    if (!grown) {
                        for (int k=0;k<count;k++) free(result[k]);
                        free(result); *returnSize=0; *returnColumnSizes=NULL; return NULL;
                    }
                    result=grown;
                }
                result[count]=malloc(3*sizeof(int));
                if (!result[count]) break;
                result[count][0]=nums[i];
                result[count][1]=nums[left];
                result[count][2]=nums[right];
                count++; left++; right--;
                while (left<right && nums[left]==nums[left-1]) left++;
                while (left<right && nums[right]==nums[right+1]) right--;
            }
        }
    }
    *returnSize=count;
    *returnColumnSizes=malloc((count ? count : 1)*sizeof(int));
    if (!*returnColumnSizes) {
        for (int k=0;k<count;k++) free(result[k]);
        free(result); *returnSize=0; return NULL;
    }
    for (int i=0;i<count;i++) (*returnColumnSizes)[i]=3;
    return result;
}
