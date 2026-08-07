void merge(int a[], int l , int m, int r)
{
    int i = l, j = m+1, k=0;
    int temp[r-l+1];
    while ( i<=m && j<=r)
    {
        temp[k++] = ( a[i] < a[j]) ? a[i++] : a[j++];
    }

    while (i<=m)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for ( i=l, k=0; i<=r; i++, k++)
        a[i] = temp[k];

}

void mergesort( int a[], int l , int r)
{
    if ( l>=r) return;
    int m = (l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1, r);
    merge(a,l,m,r);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    mergesort(nums, 0, numsSize-1);
    int min = INT_MAX;
    int ans = nums[0]+nums[1]+nums[2];
    for ( int i =0; i< numsSize -2; i++)
    {
        if ( i>0 && nums[i] == nums[i-1])
            continue;
        int l = i+1, r =numsSize - 1;
        while (l<r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(target-sum)< min)
            {
                min = abs(target-sum);
                ans = sum;
            }
            
            if (sum<target)
                l++;
            else
                r--;
        }
    }
    
    return ans;
}
