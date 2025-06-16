class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        int res=nums[0]+nums[1]+nums[2]; //res me pehle starting ki values put kar di
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                int sum=(nums[i]+nums[start]+nums[end]);
                if(sum==target) return sum;   //if sum exactly matches to target
                 if(abs(target-sum)<abs(target-res)){ 
                   res=sum;
                 }
                if (sum< target) { //if target is greater then increase from left
                    start++;
                } else {
                    end--;
                }
            }

        }
        return res;
    }
};