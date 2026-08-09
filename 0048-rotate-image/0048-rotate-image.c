void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i=0; i<matrixSize; i++)
    {
        for (int j = i+1; j<matrixSize; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] =temp;
        }
    }

    for ( int i = 0; i<matrixSize; i++)
    {
        int l = 0;
        int r = matrixSize-1;
        while (l<r)
        {
            int temp = matrix[i][l];
            matrix[i][l] = matrix[i][r];
            matrix[i][r] = temp;
            l++;
            r--;
        }
    }
}