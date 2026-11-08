int countServers(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int row[250] = {0};
    int col[250] = {0};

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 1) 
            {
                row[i]++;
                col[j]++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 1 &&
                (row[i] > 1 || col[j] > 1)) 
            {
                count++;
            }
        }
    }

    return count;
}