#include <bits/stdc++.h>
using namespace std;

class solution{
 private:
      int recursive(int n){
        if(n<=1) return n;
        return (recursive(n-1) + recursive(n-2));
      }
      int recursiveAndmemo(int n){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return (recursiveAndmemo(n-1)+recursiveAndmemo(n-2));
      }
      int bottomup(int n){
        if(n<=1) return n;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
      }
      int so(int n){
        int curr;
        if(n<=1) return n;
        int prev2=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
      }

 public:
      int dp[31]; //intialising dp with size 31
      int fibo(int& n){
        memset(dp,-1,sizeof(dp));
        return so(n);
      }
};
int main(){
    int temp;
    cin>>temp;
    solution sol;
    cout<<sol.fibo(temp)<<endl;
    return 0;
}