class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size(), left = 0, maxi = 1, mask = nums[0];

        for(int right=1;right<n;right++) { 
            while ((mask & nums[right]) != 0) 
            mask -= nums[left++];
            mask += nums[right];
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};