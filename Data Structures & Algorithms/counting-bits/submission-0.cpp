#include <vector>
class Solution {
public:
    int countBitsforNumber(int num){
        int cnt = 0;
        while(num){
            num &= num - 1;
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> out;
        for(int i = 0; i <= n ; i++){
            out.push_back(countBitsforNumber(i));
        }
        return out; 
    }
};
