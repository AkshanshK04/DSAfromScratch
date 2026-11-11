long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long ans1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;

    int mx = (need1 > need2) ? need1 : need2;
    int mn = (need1 < need2) ? need1 : need2;

    long long ans2 = 1LL * mx * costBoth;

    long long ans3 = 1LL * mn * costBoth
                   + 1LL * (need1 - mn) * cost1
                   + 1LL * (need2 - mn) * cost2;

    long long ans = ans1;

    if (ans2 < ans) ans = ans2;
    if (ans3 < ans) ans = ans3;

    return ans;
}