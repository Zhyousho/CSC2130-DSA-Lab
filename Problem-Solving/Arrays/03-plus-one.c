#include <stdlib.h>
/* LeetCode: Plus One */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize=digitsSize;
    int carry=1;
    int* arr=malloc((digitsSize+1)*sizeof(int));
    if (!arr) { *returnSize=0; return NULL; }
    for (int i=digitsSize-1; i>=0; i--) {
        int sum=digits[i]+carry;
        arr[i+1]=sum%10;
        carry=sum/10;
    }
    if (carry) {
        arr[0]=carry;
        *returnSize=digitsSize+1;
        return arr;
    }
    for (int i=0; i<digitsSize; i++) arr[i]=arr[i+1];
    return arr;
}
