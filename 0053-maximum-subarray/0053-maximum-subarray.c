int maxSubArray(int* nums, int numsSize) {
    int now = nums[0];
    int max = nums[0] ;

    for ( int i=1; i<numsSize; i++)
    {
        if ( now + nums[i] > nums[i])
            now += nums[i] ;
        else 
            now = nums[i];
        
        if (now > max)
            max = now;
    }

    return max;
}