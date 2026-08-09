int jump(int* nums, int numsSize) {
    int jumps = 0;
    int far = 0;
    int now = 0;
    for ( int i =0; i<numsSize; i++)
    {
        if (numsSize <=1)
            return 0;
        if ( far< i+nums[i])
            far = i+nums[i];
            
        if ( i == now)
        {
            jumps++;
            now = far;
        }
        
        if ( now >= numsSize-1)
            return jumps;
    }
    return jumps;
}