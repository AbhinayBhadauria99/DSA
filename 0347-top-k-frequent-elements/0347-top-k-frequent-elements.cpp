class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        vector<int> res;
        for (auto it: mpp) {
            res.push_back(it.first); 
        }

        sort(res.begin(), res.end(), [&](int a, int b) {
            return mpp[a] > mpp[b]; 
        });

        res.resize(k); // Keep only the top K elements
        return res;
    }
};