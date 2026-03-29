class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        int right = 0;
        int max_area = 0;
        while(right < heights.size()){
            int min_height = heights[right];
            for(int left = right; left >= 0; left--){
                min_height = min(heights[left],min_height);
                int area = min_height * (right - left + 1);
                if(max_area < area) max_area = area;
            }
            right++;
        }

        return max_area;
    }
};
