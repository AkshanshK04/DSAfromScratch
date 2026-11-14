#include <limits.h>
int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int minSum = INT_MAX;

    for (int i = 0; i < numsSize; i++) 
    {
        int sum = 0;

        for (int j = i; j < numsSize && j < i + r; j++) 
        {
            sum += nums[j];

            int len = j - i + 1;

            if (len >= l && len <= r && sum > 0) 
            {
                if (sum < minSum) 
                {
                    minSum = sum;
                }
            }
        }
    }

    return minSum == INT_MAX ? -1 : minSum;
}