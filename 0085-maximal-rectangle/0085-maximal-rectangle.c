int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if ( matrixSize == 0 || matrixColSize == 0)
        return 0;
    
    int cols = *matrixColSize;
    int heights[cols];
    int stack[cols + 1];

    for ( int j=0; j<cols; j++)
    {
        heights[j] = 0;
    }

    int ans = 0;

    for ( int i = 0; i<matrixSize; i++)
    {
        for ( int j = 0; j< cols; j++)
        {
            if ( matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        int top = -1;

        for ( int j = 0; j<= cols; j++)
        {
            int curr = (j == cols) ? 0 : heights[j];

            while ( top >= 0 && heights[stack[top]] > curr)
            {
                int h = heights[stack[top--]];
                int l = ( top >= 0) ? stack[top] : -1;
                int area = h*(j-l-1);

                if ( area > ans)
                    ans = area;
            }

            stack[++top] = j;
        }
    }

    return ans;
}