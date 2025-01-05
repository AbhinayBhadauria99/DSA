#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(nums,0);
    }
private:
    int helper(vector<int>& nums,int index){
       if(index>=nums.size()) return 0;
       if(dp[index]!=-1) return dp[index];
       int steal=nums[index]+helper(nums,index+2);
       int skip=helper(nums,index+1);
       return dp[index]=max(steal,skip);
    }
};
int main() {
    int n;
    vector<int> nums;

    cout << "Enter space-separated numbers ";
    string input;
    getline(cin, input); // Read the entire input line

    stringstream ss(input); // Parse the input
    int num;
    while (ss >> num) {
        nums.push_back(num); // Add numbers to the vector
    }

    Solution sol;
    cout << sol.rob(nums) << endl; // Output result
    return 0;
}