/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if ( matrixSize == 0 || matrixColSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* res = malloc(rows*cols*sizeof(int));

    int top = 0;
    int bottom = rows-1;
    int left = 0;
    int right = cols-1;

    int k = 0;
    while ( top<= bottom && left <= right)
    {
        for ( int j =left ; j<= right; j++)
        {
            res[k++] = matrix[top][j];
        }

        top++;

        for ( int i= top ; i<= bottom; i++)
        {
            res[k++] = matrix[i][right];
        }

        right--;

        if ( top <= bottom)
        {
            for ( int j = right; j>= left ; j--)
            {
                res[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        if (left<= right)
        {
            for ( int i = bottom; i>= top; i--)
            {
                res[k++] = matrix[i][left];

            }
            left++;
        }
    }

    *returnSize = k;
    return res;
}