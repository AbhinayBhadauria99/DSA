class Solution {
public:
    int total=0;
    void helper(vector<vector<int>>& res,int idx,vector<int>& nums,vector<int> temp){
        if(idx==nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        helper(res,idx+1,nums,temp);
        temp.pop_back();
        helper(res,idx+1,nums,temp);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,0,nums,temp);
        int result=0;

        for(auto it: res){
            int xaur=0;
            for(auto it2: it){
                xaur^=it2;
            }
            result+=xaur;
        }
        return result;
    }
};