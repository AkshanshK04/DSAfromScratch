/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(numRows * sizeof(int *));
    *returnColumnSizes = malloc(numRows * sizeof(int));

    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        int size = i + 1;

        ans[i] = malloc(size * sizeof(int));
        (*returnColumnSizes)[i] = size;

        ans[i][0] = 1;
        ans[i][size - 1] = 1;

        for (int j = 1; j < size - 1; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}