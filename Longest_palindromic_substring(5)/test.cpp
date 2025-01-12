#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindromewithbruteforce(string s) { //find all possible combination if they are palindrome the store in res
      int resLen=0;
        string res;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                int left=i;
                int right=j;
                while(left<=right && s[left]==s[right]){  //palindrome check
                      left++;
                      right--;
                }
                if(left>=right && j-i+1>resLen){ //left,right variables have already been manipulated after palindrome.check above
                    res=s.substr(i,j-i+1);
                    resLen=j-i+1;
                }
            }
        }
        return res;
    }
    string longestPalindromewithdp(string s) {
        int resIndx=0;
        int resLen=0;
        int n= s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false)); //2d boolean array
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                 if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){ //check notes
                    dp[i][j]=true;
                    if(resLen<(j-i+1)){
                        resIndx=i;
                        resLen=j-i+1;
                    }
                 }
            }
        }
        return s.substr(resIndx,resLen);
    }
};

int main() {
    Solution solution;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;
    
    string result = solution.longestPalindromewithdp(s);
    cout << "The longest palindromic substring is: " << result << endl;

    return 0;
}
