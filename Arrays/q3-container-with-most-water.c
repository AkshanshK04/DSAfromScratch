int maxArea(int* height, int heightSize) {
    int i = 0, j=heightSize - 1, max_amt = 0, each_amt=0;
    while ( i < j)
    {
        int h = height[i] < height[j] ? height[i] : height[j];
        each_amt = (j-i)*h;
        if (each_amt > max_amt)
            max_amt = each_amt;
        if (height[i] <height[j])
            i++;
        else
            j--;
    }
    return max_amt;
}