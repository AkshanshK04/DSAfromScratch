char* intToRoman(int num) {
    int val[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* sym [] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* res = malloc(20*sizeof(char));
    int pos = 0;
    for ( int i=0; i<13; i++)
    {
        while ( num >= val[i])
        {
            num-= val[i];
            for ( int j = 0; sym[i][j] != '\0'; j++)
                res[pos++] = sym[i][j];
        }
    }

    res[pos] = '\0';
    return res;
}