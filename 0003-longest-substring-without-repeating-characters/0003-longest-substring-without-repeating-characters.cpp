class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        int count =0;
        int maxcount=0;
        unordered_map<int,int> mpp;
        for(auto it: s){
            if(mpp[it]){
                while(s[start] != it){
                    mpp[s[start]]--;
                    count--;
                    start++;
                }
                mpp[s[start]]--;
                count--;
                start++;
            }
            count++;
            end++;
            mpp[it]++;
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};