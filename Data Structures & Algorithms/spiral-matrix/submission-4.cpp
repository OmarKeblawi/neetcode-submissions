class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        if(matrix.size() == 1)  return matrix[0];
        vector<int> out;
        if(matrix[0].size() == 1){
            for(int i = 0; i < matrix.size(); i++){
                out.push_back(matrix[i][0]);
            }
            return out;
        }

        // for one layer:
        int upper_bound = 0;
        int left_bound = 0; 
        int right_bound = matrix[0].size();
        int bottom_bound = matrix.size();
        while(1){
            
            for(int i = left_bound ; i < right_bound; i++){
                out.push_back(matrix[upper_bound][i]);
            }
            upper_bound++;
            if(upper_bound == bottom_bound) break;
            for(int i = upper_bound; i < bottom_bound; i++){
                out.push_back(matrix[i][right_bound-1]);
            }
            right_bound--;
            if(right_bound == left_bound) break;
            for(int i = right_bound - 1 ; i >= left_bound ; i--){
                out.push_back(matrix[bottom_bound - 1][i]);
            }
            bottom_bound--;
            if(upper_bound == bottom_bound) break;
            for(int i = bottom_bound - 1; i >= upper_bound ; i-- ){
                out.push_back(matrix[i][left_bound]);
            }
            left_bound++;
            if(right_bound == left_bound) break;
        }
        return out;
    }
};
