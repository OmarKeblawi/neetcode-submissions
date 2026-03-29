#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        stack<pair<int,int>> st;
        int max_area = 0;
        for(int i = 0 ; i < heights.size(); i++){
            int min_idx = i;
            while(!st.empty() && (heights[st.top().second] > heights[i])){
                auto p = st.top();
                min_idx = min(min_idx, p.first);
                int cur_area = heights[p.second] * (i - p.first); 
                max_area = max(max_area,cur_area);
                st.pop();
            }
            st.push({min_idx,i});
        }

        while(!st.empty()){
            auto p = st.top();
            int cur_area = heights[p.second] * (heights.size() - p.first);
            max_area = max(max_area,cur_area);
            st.pop();
        }

        return max_area;
    }
};
