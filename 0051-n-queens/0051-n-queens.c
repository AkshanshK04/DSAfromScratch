/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack ( int row, int n, char** board,int* cols, int* diag1, int* diag2,char*** res, int* returnSize)
{
    if (row == n)
    {
        res[*returnSize ]  = malloc(n*sizeof(char*));
        for (int i=0; i<n; i++)
        {
            res[*returnSize][i] = malloc((n+1)*sizeof(char));
            strcpy(res[*returnSize][i], board[i]);
        }

        (*returnSize)++;
        return;
    }

    for ( int i = 0; i<n; i++)
    {
        int d1 = row -i +n-1;
        int d2 = row+i;

        if ( cols[i] || diag1[d1] || diag2[d2])
            continue;
        
        board[row][i] = 'Q';
        cols[i] =1;
        diag1[d1] = 1;
        diag2[d2] = 1;

        backtrack ( row+1, n, board, cols, diag1, diag2, res, returnSize);

        board[row][i] = '.';
        cols[i] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    
    }

}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char*** res = malloc(10000*sizeof(char**));
    char** board = malloc(n*sizeof(char*));

    for ( int i = 0; i<n ; i++)
    {
        board[i] = malloc((n+1)*sizeof(char));

        for ( int j=0; j<n; j++)
            board[i][j] = '.';
        
        board[i][n] = '\0';
    }

    int* cols = calloc(n, sizeof(int));
    int* diag1 = calloc(2*n-1, sizeof(int));
    int* diag2 = calloc(2*n-1, sizeof(int));

    *returnSize = 0;
    backtrack ( 0, n, board, cols, diag1, diag2, res, returnSize);

    *returnColumnSizes = malloc((*returnSize)*sizeof(int));

    for ( int i = 0; i<*returnSize; i++)
    {
        (*returnColumnSizes)[i] = n;
    }

    for ( int i=0; i<n; i++)
    {
        free(board[i]);
    }

    free(board);
    free(cols);
    free(diag1);
    free(diag2);

    return res;
}