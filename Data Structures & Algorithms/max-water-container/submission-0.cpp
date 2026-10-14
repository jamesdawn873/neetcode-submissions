class Solution {
public:
    int maxArea(vector<int>& heights) {
       int right = heights.size() - 1, left = 0;
       int maxarea = 0;
       while (left < right){
        maxarea = max(min(heights[left], heights[right]) * (right - left), maxarea);
        if (heights[left] < heights[right]) {
            left++;
        } else { right--; }
       }
       return maxarea;
    }
};
