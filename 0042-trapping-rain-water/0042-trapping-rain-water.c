int trap(int* height, int heightSize) {
    int lmax = 0, rmax = 0;
    int l = 0, r= heightSize-1;
    int sum = 0;
    while ( l<r)
    {
        if (height[l] <= height[r])
        {
            if ( height[l] > lmax)
                lmax = height[l];
            else
                sum += lmax - height[l];

            l++;
        }

        else 
        {
            if (height[r] >= rmax)
                rmax = height[r];
            else
                sum += rmax -height[r];
            r--;
        }
    }

    return sum;
}