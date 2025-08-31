class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKPos=-1;
        int maxKPos=-1;
        int culpritIndex=-1;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK) minKPos=i;
            if(nums[i]==maxK) maxKPos=i;
            if(nums[i]>maxK || nums[i]<minK) culpritIndex=i;
            int smaller=min(minKPos,maxKPos);
            if(smaller-culpritIndex>0){
                res+=smaller-culpritIndex;
            }
        }
        return res;
    }
};