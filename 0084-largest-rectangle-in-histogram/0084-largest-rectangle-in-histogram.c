int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize + 1];
    int top = -1;
    int area = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int curr = (i == heightsSize) ? 0 : heights[i];

        while (top >= 0 && heights[stack[top]] > curr) {
            int h = heights[stack[top--]];

            int width;
            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int currArea = h * width;

            if (currArea > area)
                area = currArea;
        }

        stack[++top] = i;
    }

    return area;
}