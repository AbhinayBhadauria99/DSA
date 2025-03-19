class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0; 
        int sum =0; //cumulative sum
        //keep finding cumulative sum of array andd adding in mpp,later check if sum-k is present in mpp
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]++;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){ 
                // If (sum - k) exists in the map, it means a subarray with sum = k can be formed.  
               cnt += mpp[sum - k];   
                // For example, if the map contains {5 -> 2}, it means the prefix sum 5 has appeared twice.  
                // This implies that there are 2 possible subarrays that sum to k.  
                // Instead of incrementing cnt by 1, we add mpp[sum - k] to count all possible subarrays.
            }
            mpp[sum]++;
            
        }
        return cnt;
    }
};