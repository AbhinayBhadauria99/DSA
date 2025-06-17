class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int i = n-1; i >= 0; i--) { //traverse from back 
            if(st.count(nums[i])) {
                return ceil((i+1)/3.0);   //total possible operations
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};
