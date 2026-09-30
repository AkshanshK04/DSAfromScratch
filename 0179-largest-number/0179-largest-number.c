char* largestNumber(int* nums, int numsSize) {
    char *ans = malloc(numsSize * 12 + 1);
    char a[25], b[25], ab[50], ba[50];
    int i, j, temp;

    for (i = 0; i < numsSize - 1; i++) 
    {
        for (j = 0; j < numsSize - i - 1; j++) 
        {
            sprintf(a, "%d", nums[j]);
            sprintf(b, "%d", nums[j + 1]);

            sprintf(ab, "%s%s", a, b);
            sprintf(ba, "%s%s", b, a);

            if (strcmp(ab, ba) < 0) 
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    ans[0] = '\0';

    for (i = 0; i < numsSize; i++) 
    {
        char tempstr[25];
        sprintf(tempstr, "%d", nums[i]);
        strcat(ans, tempstr);
    }

    if (ans[0] == '0')
        ans[1] = '\0';

    return ans;
}