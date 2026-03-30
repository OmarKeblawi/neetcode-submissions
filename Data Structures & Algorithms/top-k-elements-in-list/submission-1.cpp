class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;

        // Max-heap by frequency: (freq, num)
        priority_queue<pair<int,int>> heap;
        for (auto &p : freq) {
            heap.push({p.second, p.first});
        }

        vector<int> out;
        for (int i = 0; i < k && !heap.empty(); ++i) {
            out.push_back(heap.top().second);
            heap.pop();
        }
        return out;
    }
};