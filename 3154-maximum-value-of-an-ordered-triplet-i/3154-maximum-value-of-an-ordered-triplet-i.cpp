class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long long res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                   res=max(res,1LL * (nums[i] - nums[j]) * 1LL * nums[k] );
                }
            }
        }
        return res>0? res:0;
    }
};