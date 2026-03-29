class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        int end = matrix.size() - 1;
        int prev_val, cur_val;
        for(int n = matrix.size(); n > 1 ; n-=2){
            for(int i = start; i < end ; i++){
                prev_val = matrix[i][end];
                matrix[i][end] = matrix[start][i];
                cur_val = matrix[end][(end + start) - i];
                matrix[end][(end + start) - i] = prev_val;
                prev_val = cur_val;
                cur_val = matrix[(end + start) - i][start];
                matrix[(end + start) - i][start] = prev_val;
                prev_val = cur_val;
                matrix[start][i] = prev_val;
            }
            start++;
            end--;
        }
    }
};
