class Solution {
public:
    bool helper(int idx,int currsum,vector<int>& nums, int k,int target,vector<bool>& vis){
        if(k==0) return true;
        if(currsum>target) return false;
        if(currsum==target){
            return helper(0,0,nums,k-1,target,vis); //to check all buckets
        }

        for(int i=idx;i<nums.size();i++){
            if(vis[i]) continue;
            vis[i]=true;
            if(helper(i+1,currsum+nums[i],nums,k,target,vis)) return true;  //to check all possibility of single bucket
            vis[i]=false;
            
            //skip duplicates
            if (currsum == 0) return false;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
            }           
    return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum= accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        if(sum%k!=0) return false;
        int target=sum/k;
        if(nums[0]>target) return false;

        vector<bool> vis(nums.size(),false);
       return helper(0,0,nums,k,target,vis);
       
    }
};