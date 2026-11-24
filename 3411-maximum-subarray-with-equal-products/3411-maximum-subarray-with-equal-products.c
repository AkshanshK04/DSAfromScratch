#include <stdlib.h>

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int maxLength(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        long long product = 1;
        long long lcm = 1;
        int g = 0;

        for (int j = i; j < numsSize; j++) 
        {
            g = gcd(g, nums[j]);

            if (product > 1000000000000000000LL / nums[j])
                break;

            product *= nums[j];

            int d = gcd((int)(lcm % nums[j]), nums[j]);
            long long factor = nums[j] / gcd((int)(lcm % nums[j]), nums[j]);

            if (lcm > 1000000000000000000LL / factor)
                break;

            lcm *= factor;

            if (lcm <= 1000000000000000000LL / g &&
                product == lcm * g) 
                {
                int len = j - i + 1;
                if (len > ans)
                    ans = len;
            }
        }
    }

    return ans;
}
