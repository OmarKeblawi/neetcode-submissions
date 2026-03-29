#include <unordered_map>
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> occ;
        int cur = 0;
        vector<int> res;
        for(int i = 0 ; i < s.size() ; i++){
            occ[s[i]] = i;
        }
        int size = 0, end = 0;
        for(int i = 0; i < s.size() ; i++){
            size++;
            end = max(end, occ[s[i]]);
            if(end == i){
                res.push_back(size);
                size = 0;
            }
        }
        return res;   
    }
};
