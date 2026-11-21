/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *result = malloc(2 * sizeof(int));
    *returnSize = 0;

    int member1 = 0, member2 = 1;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] == member1) 
        {
            count1++;
        }
        else if (nums[i] == member2) 
        {
            count2++;
        }
        else if (count1 == 0) 
        {
            member1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0) 
        {
            member2 = nums[i];
            count2 = 1;
        }
        else 
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] == member1)
            count1++;
        else if (nums[i] == member2)
            count2++;
    }

    if (count1 > numsSize / 3)
        result[(*returnSize)++] = member1;

    if (count2 > numsSize / 3)
        result[(*returnSize)++] = member2;

    return result;
}