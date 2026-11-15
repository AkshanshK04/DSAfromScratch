int numOfSubarrays(int* arr, int arrSize) {
    const int mod = 1000000007;

    long long even = 1, odd = 0;
    long long sum = 0, ans = 0;

    for (int i = 0; i < arrSize; i++) 
    {
        sum += arr[i];

        if (sum % 2 == 0) 
        {
            ans += odd;
            even++;
        } 
        else 
        {
            ans += even;
            odd++;
        }

        ans %= mod;
    }

    return (int)ans;
}