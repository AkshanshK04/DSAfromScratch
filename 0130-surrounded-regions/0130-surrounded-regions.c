void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0) return;

    int m = boardSize, n = boardColSize[0];
    int total = m * n;
    int s[total];
    int top = 0;

    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') {
            board[i][0] = '#';
            s[top++] = i * n;
        }
        if (n > 1 && board[i][n - 1] == 'O') {
            board[i][n - 1] = '#';
            s[top++] = i * n + n - 1;
        }
    }

    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') {
            board[0][j] = '#';
            s[top++] = j;
        }
        if (m > 1 && board[m - 1][j] == 'O') {
            board[m - 1][j] = '#';
            s[top++] = (m - 1) * n + j;
        }
    }

    while (top > 0) {
        int pos = s[--top];
        int r = pos / n;
        int c = pos % n;

        if (r > 0 && board[r - 1][c] == 'O') {
            board[r - 1][c] = '#';
            s[top++] = (r - 1) * n + c;
        }
        if (r + 1 < m && board[r + 1][c] == 'O') {
            board[r + 1][c] = '#';
            s[top++] = (r + 1) * n + c;
        }
        if (c > 0 && board[r][c - 1] == 'O') {
            board[r][c - 1] = '#';
            s[top++] = r * n + c - 1;
        }
        if (c + 1 < n && board[r][c + 1] == 'O') {
            board[r][c + 1] = '#';
            s[top++] = r * n + c + 1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}