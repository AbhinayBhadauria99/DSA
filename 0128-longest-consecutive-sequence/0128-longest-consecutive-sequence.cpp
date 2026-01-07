class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int count=1;
        int s=1;
        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
         
             if (nums[i] == nums[i - 1]) {
                continue;
            }
            if(nums[i]==nums[i-1]+1){
                count++;
                 s= max(s,count);
            }  
            else{
                count=1;
            }        
                
        }
        return s;
    }
};