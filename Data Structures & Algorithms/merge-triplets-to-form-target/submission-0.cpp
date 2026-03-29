class Solution {
public:
    bool isSmaller(vector<int>& check, vector<int>& target){
        if(check[0] <= target[0] && check[1] <= target[1] && check[2] <= target[2]) 
        return true;

        return false;
    }
    bool isEqual(vector<int>& check, vector<int>& target){
        if(check[0] == target[0] && check[1] == target[1] && check[2] == target[2]) return true;
        return false;
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int current = 0;
        while(current < triplets.size() && !isSmaller(triplets[current], target)) current++;
        if(current == triplets.size()) return false;
        vector<int> cur_trip = triplets[current];
        current++;
        while(!isEqual(cur_trip,target) && current < triplets.size()  ){
            if(isSmaller(triplets[current], target)){
                cur_trip[0] = max(triplets[current][0], cur_trip[0]);
                cur_trip[1] = max(triplets[current][1], cur_trip[1]);
                cur_trip[2] = max(triplets[current][2], cur_trip[2]);
                if(isEqual(cur_trip,target)) return true;
            }
            current++;
        }
        return isEqual(cur_trip,target);
    }
};
