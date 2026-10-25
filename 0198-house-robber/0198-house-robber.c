int rob(int* nums, int numsSize) {
    int prev2 = 0, prev1 = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        int curr = prev1;
        if (prev2 + nums[i] > curr) 
            curr = prev2 + nums[i];

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}