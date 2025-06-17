class Solution {
public:
    long long helper(int pointer, vector<vector<int>>& questions,vector<long long>& dp){  //pass dp by reference 
       int n= questions.size();
       if(pointer>=n){
        return 0;
       }
       if(dp[pointer]!= -1) return dp[pointer];
        long count=questions[pointer][0] + helper(pointer+questions[pointer][1]+1,questions,dp);
        long skip=helper(pointer+1,questions,dp);

        
       return dp[pointer]=max(count,skip);     
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n= questions.size();
        vector<long long> dp(n, -1);  // initialize memoization table with -1           
        return helper(0,questions,dp);
    }
};