char* convert(char* s, int numRows) {
    int len = strlen(s);

    if ( numRows == 1 || numRows >= len)
    {
        char* res = malloc((len+1) * sizeof(char));
        strcpy(res,s);
        return res;
    }

    char** rows = malloc((numRows+1)*sizeof(char*));
    for (int i =0 ; i<numRows; i++)
    {
        rows[i] = malloc((len+1)*sizeof(char));
        rows[i][0] = '\0';
    }

    int currow = 0;
    int dir = 1;

    for ( int i=0; i< len; i++)
    {
        int rowlen = strlen(rows[currow]);
        rows[currow][rowlen] = s[i];
        rows[currow][rowlen+1] = '\0';

        if ( currow == numRows - 1)
            dir = -1;
        else if ( currow == 0)
            dir =1;
        
        currow += dir;
    }

    char* res = malloc((len+1)*sizeof(char));
    res[0] = '\0';

    for ( int i=0; i<numRows; i++)
    {
        strcat(res, rows[i]);
        free(rows[i]);
    }

    free(rows);
    return res;
}