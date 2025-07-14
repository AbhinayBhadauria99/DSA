class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int>& temp,unordered_map<int,int>& mpp){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(auto [number,val]: mpp){
            if(val==0) continue;
            //DO
            temp.push_back(number);
            mpp[number]--;
           
            //CALL
            helper(nums,temp,mpp);

            //UNDO
            temp.pop_back();
            mpp[number]++;

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {       
        vector<int> temp;
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        helper(nums,temp,mpp);
        return res;        
    }
};   