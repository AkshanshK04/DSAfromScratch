bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];

    bool dfs(int r, int c, int idx)
    {
        if ( word[idx] == '\0')
            return true;
        
        if ( r<0 || r>= rows || c <0 || c >= cols || board[r][c] != word[idx] )
        {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool find = dfs (r+1, c, idx+1) || dfs(r-1, c, idx+1) || dfs(r, c+1, idx+1) || dfs(r, c-1, idx+1);

        board[r][c] = temp;
        return find;
    }

    for ( int i=0; i< rows; i++)
    {
        for ( int j=0; j<cols; j++)
        {
            if ( dfs(i,j,0))
                return true;
        }
    }

    return false;
}