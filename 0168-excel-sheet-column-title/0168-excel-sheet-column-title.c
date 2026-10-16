char* convertToTitle(int columnNumber) {
    char *res = (char *)malloc(10 * sizeof(char));
    int i = 0;

    while (columnNumber > 0) 
    {
        columnNumber--;
        res[i++] = 'A' + (columnNumber % 26);
        columnNumber /= 26;
    }

    res[i] = '\0';

    for (int j = 0; j < i / 2; j++) 
    {
        char temp = res[j];
        res[j] = res[i - j - 1];
        res[i - j - 1] = temp;
    }

    return res;
}