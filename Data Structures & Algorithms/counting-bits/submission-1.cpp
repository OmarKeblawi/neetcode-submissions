#include <vector>
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n+1);
        for(int i = 1; i <= n ; i++){
           out[i] = out[i>>1] + (i&1);
        }
        return out; 
    }
};
