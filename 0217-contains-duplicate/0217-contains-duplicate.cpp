class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return false;
        for (int i=1;i<nums.size();i++){
            if((nums[i-1]^nums[i])==0) return true;
        }      
        return false;
    }
};