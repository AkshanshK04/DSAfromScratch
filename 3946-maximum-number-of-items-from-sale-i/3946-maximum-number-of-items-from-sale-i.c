int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int dp[1501] = {0};
    int minPrice = 1501;

    for (int i = 0; i < itemsSize; i++) 
    {
        int factor = items[i][0];
        int price = items[i][1];

        if (price < minPrice)
            minPrice = price;

        int count = 0;

        for (int j = 0; j < itemsSize; j++) 
        {
            if (items[j][0] % factor == 0) 
            {
                count++;
            }
        }

        for (int j = budget; j >= price; j--) 
        {
            int val = dp[j - price] + count;

            if (val > dp[j])
                dp[j] = val;
        }
    }

    int ans = 0;

    for (int i = 0; i <= budget; i++) 
    {
        int total = dp[i] + (budget - i) / minPrice;

        if (total > ans)
            ans = total;
    }

    return ans;
}