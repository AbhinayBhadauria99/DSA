#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101];
    int  memoization(string s, int index){
      if(index==s.length()) return dp[index]=1;
      if(s[index]=='0') return dp[index]=0;
      if(dp[index]!=-1) return dp[index];
      int res= memoization(s,index+1);
      if(index+1<s.length()){    //to check if i+1 will availble or its out of bounds
        if(s[index]=='1' || (s[index]=='2' && s[index+1]<='6')){  //either number is 1 or if its 2 then next no less than 6 so that threshold of 26 dont get voilated.
          res+=memoization(s,index+2);   //adding this possibility in res and shifting index to index+2
        }
      }
      return dp[index]=res;
    }

    int tabulation(string s) {
        vector<int> dp(s.length()+1);
        dp[s.length()]=1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
                dp[i]=dp[i+1];
                if(i+1<s.length()){
                    if(s[i]=='1' ||(s[i]=='2' && s[i+1]<'7')){
                    dp[i]+=dp[i+2];
                   }
                }
            }
        }
    return dp[0];
    }
};


int main(){  
    Solution solution;
    string s;
    memset(solution.dp,-1,sizeof(solution.dp));  //only for memoization

    cout << "Enter the encoded string: ";
    cin >> s;

    // Call the function and print the result
    int result = solution.memoization(s,0);
    cout << "Number of ways to decode the string: " << result << endl;

    return 0;
}