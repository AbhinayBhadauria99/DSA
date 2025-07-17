class Solution {
public:
    int total=0;
    void helper(vector<vector<int>>& res,int xaur,int idx,vector<int>& nums){
        if(idx==nums.size()){
            total+=xaur;
            return;
        }

        helper(res,xaur^nums[idx],idx+1,nums);
        helper(res,xaur,idx+1,nums);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int xaur=0;
        helper(res,xaur,0,nums);

        return total;
    }
};