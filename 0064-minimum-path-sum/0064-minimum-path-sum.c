int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int t[cols];

    t[0] = grid[0][0];
    for ( int i = 1; i< cols; i++)
    {
        t[i] = t[i-1] + grid[0][i];
    }

    for ( int i=1; i<rows; i++)
    {
        t[0] += grid[i][0];
        for ( int j= 1; j<cols ; j++)
        {
            t[j] = grid[i][j] + ( t[j] < t[j-1] ? t[j]:t[j-1]);
        }
    }

    return t[cols-1];
}