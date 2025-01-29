#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int dfs(int i,int j,int m,int n){
    if(i==(m-1) && j==(n-1)) return 1;  //reached end
    if(i>=m || j>=n) return 0;  //out of bound 
    if(dp[i][j]!=-1) return dp[i][j];   //memoization
    return dp[i][j]= dfs(i,j+1,m,n) + dfs(i+1,j,m,n); //robot can only move down and right
  };


int uniquePaths(int m, int n) {
      dp.resize(m,vector<int>(n,-1));  // initialize a 2d array for memoization
      return dfs(0,0,m,n);  //robot starts from (0,0)
    };


int main() {
    int m, n;
    cout<<"Enter value of m, press enter and then enter value of n"<<endl;
    cin >> m >> n;
    cout <<uniquePaths(m, n) << endl;
    return 0;
}
