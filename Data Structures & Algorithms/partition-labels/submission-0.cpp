#include <unordered_map>
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> occ;
        int cur = 0;
        unordered_set<char> set;
        vector<int> ret;
        int sub = 0;
        for(char c : s){
            occ[c]++;
        }
        while(cur < s.size()){
            sub = 1;
            occ[s[cur]]--;
            if(occ[s[cur]] > 0){
                set.insert(s[cur]);
            }
            while(set.size()){
                cur++;
                sub++;
                occ[s[cur]]--;
                if(occ[s[cur]] == 0){
                    set.erase(s[cur]);
                }
                else{
                    set.insert(s[cur]);
                }
            }
            ret.push_back(sub);
            cur++;
        }
        return ret;   
    }
};
