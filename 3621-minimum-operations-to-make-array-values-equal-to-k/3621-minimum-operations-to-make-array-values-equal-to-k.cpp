class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
       for(auto it:nums){
        if(it<k) return -1;   //if given k is bigger than any value of nums then you cant make all elements nums equal after what so ever times operations you perform .because integer h must also be valid.
        else if(it>k) mpp[it]++;
       }
       return mpp.size();
    }
};