void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    int row[m];
    int col[n];

    for ( int i = 0; i < m; i++)
    {
        row[i] = 0;
    }
    for ( int j = 0; j < n; j++)
    {
        col[j] = 0;
    }

    for ( int i =0 ; i < m ; i++)
    {
        for ( int j =0 ; j< n; j++)
        {
            if ( matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for ( int i = 0; i < m; i++)
    {
        if (row[i])
        {
            for ( int j = 0; j<n; j++)
                matrix[i][j] = 0;
        }
    }

    for ( int j = 0; j<n; j++)
    {
        if (col[j])
        {
            for ( int i = 0; i<m; i++)
                matrix[i][j] = 0;
        }
    }
}