int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    int t[n];
    memset(t, 0, sizeof(t));
    t[0] = 1;

    for ( int i=0; i<m; i++)
    {
        for ( int j=0; j<n; j++)
        {
            if ( obstacleGrid[i][j] == 1)
                    t[j] = 0;
            else if (j>0)
                    t[j] += t[j-1];
        }
    }

    return t[n-1];
}