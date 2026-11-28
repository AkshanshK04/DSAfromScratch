int cmp(const void *a, const void *b) 
{
    int *x = *(int**)a;
    int *y = *(int**)b;

    return (x[1]>y[1]) - (x[1] <y[1]);
}

int maximumSaleItems(int** items, int itemsSize,
                     int* itemsColSize, int budget) {

    int n = itemsSize;
    (void)itemsColSize;

    int *freq = calloc(n + 1, sizeof(int));
    int *cnt = calloc(n + 1, sizeof(int));

    int minPrice = 1000000000;
    int maxFactor = 0;

    for (int i = 0; i < n; i++) 
    {
        int f = items[i][0];

        freq[f]++;

        if (items[i][1] < minPrice)
            minPrice = items[i][1];

        if (f > maxFactor)
            maxFactor = f;
    }

    for (int i = 1; i <= maxFactor; i++) 
    {
        for (int j = i; j <= maxFactor; j += i) 
        {
            cnt[i] += freq[j];
        }
    }

    qsort(items, n, sizeof(int*), cmp);

    long long ans = 0;
    long long rem = budget;

    for (int i = 0; i < n; i++) 
    {

        int f = items[i][0];
        int p = items[i][1];

        if (p > 2LL * minPrice)
            break;

        int gain = cnt[f] - 1;

        if (gain <= 0)
            continue;

        long long take = rem / p;

        if (take > gain)
            take = gain;

        ans += 2LL * take;
        rem -= take * p;
    }

    ans += rem / minPrice;

    free(freq);
    free(cnt);

    return (int)ans;
}