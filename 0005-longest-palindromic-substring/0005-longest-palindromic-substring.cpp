class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int resLen=0;
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(resLen<j-i+1){
                        resLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,resLen);
    }
};