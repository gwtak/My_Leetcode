int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int area, max_area=0;

    while (left < right) {
        if (height[left] < height[right]) {
            area = height[left] * (right - left);
            left++;
        } else {
            area = height[right] * (right - left);
            right--;
        }

        if (area > max_area) max_area = area;
    }
    return max_area;
}