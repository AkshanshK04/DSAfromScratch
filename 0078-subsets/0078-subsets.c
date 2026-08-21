/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack ( int* nums, int numsSize, int start, int* curr, int currSize, int** res, int* returnSize, int** returnColumnSizes)
{
    res[*returnSize] = malloc(currSize*sizeof(int));

    for ( int i=0; i<currSize; i++)
    {
        res[*returnSize][i] = curr[i];
    }

    (*returnColumnSizes)[*returnSize] = currSize;
    (*returnSize)++;

    for ( int i =start; i<numsSize; i++)
    {
        curr[currSize] = nums[i];
        backtrack(nums, numsSize, i+1, curr, currSize+1, res, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int all = 1 << numsSize;

    int** res = malloc(all*sizeof(int*));
    *returnColumnSizes = malloc(all*sizeof(int));
    *returnSize = 0;

    int* curr = malloc(numsSize*sizeof(int));
    backtrack(nums, numsSize, 0, curr, 0, res, returnSize, returnColumnSizes);

    free(curr);
    return res;
}