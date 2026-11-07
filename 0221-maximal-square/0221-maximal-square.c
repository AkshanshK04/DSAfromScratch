int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int dp[n + 1];
    int max = 0, prev = 0;

    for (int j = 0; j <= n; j++)
        dp[j] = 0;

    for (int i = 1; i <= m; i++) 
    {
        prev = 0;

        for (int j = 1; j <= n; j++) 
        {
            int temp = dp[j];

            if (matrix[i-1][j-1] == '1') 
            {
                int a = dp[j-1];
                int b = dp[j];
                int c = prev;

                int min = a < b ? a : b;
                min = min < c ? min : c;

                dp[j] = min + 1;

                if (dp[j] > max)
                    max = dp[j];
            
            } 
            else 
            {
                dp[j] = 0;
            }

            prev = temp;
        }
    }

    return max * max;
}