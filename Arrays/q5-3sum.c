/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

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

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    mergesort(nums, 0, numsSize-1);
    int capacity = 100;
    int** ans = malloc(capacity*sizeof(int*));
    *returnColumnSizes = malloc(capacity*sizeof(int));
    *returnSize = 0;
    
    for ( int i =0; i< numsSize -2; i++)
    {
        if ( i>0 && nums[i] == nums[i-1])
            continue;
        int l = i+1, r =numsSize - 1;
        while (l<r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if ( sum == 0)
            {
                if (*returnSize == capacity)
                {
                    capacity *= 2;
                    ans = realloc(ans, capacity*sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity*sizeof(int));
                }
                ans[*returnSize] = malloc(3*sizeof(int));
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[l];
                ans[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (l<r && nums[l] == nums[l+1]) l++;
                while (l<r && nums[r] == nums[r-1]) r--;

                l++;
                r--;

            }
            
            else if (sum<0)
                l++;
            else
                r--;
        }
    }
    
    return ans;
}
