/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    free(result);
    *returnSize = 0;
    return NULL;
}