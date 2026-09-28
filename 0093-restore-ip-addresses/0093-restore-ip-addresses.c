/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = 0;

    char **result = malloc(10000 * sizeof(char*));

    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 3; b++) {
            for (int c = 1; c <= 3; c++) {
                for (int d = 1; d <= 3; d++) {

                    if (a + b + c + d != n)
                        continue;

                    char p1[4], p2[4], p3[4], p4[4];

                    strncpy(p1, s, a);
                    p1[a] = '\0';

                    strncpy(p2, s + a, b);
                    p2[b] = '\0';

                    strncpy(p3, s + a + b, c);
                    p3[c] = '\0';

                    strncpy(p4, s + a + b + c, d);
                    p4[d] = '\0';

                    if ((a > 1 && p1[0] == '0') ||
                        (b > 1 && p2[0] == '0') ||
                        (c > 1 && p3[0] == '0') ||
                        (d > 1 && p4[0] == '0'))
                        continue;

                    int n1 = atoi(p1);
                    int n2 = atoi(p2);
                    int n3 = atoi(p3);
                    int n4 = atoi(p4);

                    if (n1 > 255 || n2 > 255 ||
                        n3 > 255 || n4 > 255)
                        continue;

                    result[*returnSize] = malloc(16 * sizeof(char));

                    sprintf(result[*returnSize],
                            "%s.%s.%s.%s",
                            p1, p2, p3, p4);

                    (*returnSize)++;
                }
            }
        }
    }

    return result;
}