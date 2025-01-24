#include <bits/stdc++.h>
using namespace std;

int dp[2501][2501];

int helper(vector<int>& nums, int curr, int prev) {
    if (curr >= nums.size()) return 0; // when current hits last index return 0
    int take = 0; // initialized variables take and skip as we have 2 choices at every index
    if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1]; // if dp already has this combination of prev and curr return that, we are doing prev+1 because prev was initially -1. so it doesn’t matter if we map all prevs in dp with prev which is incremented by 1.
    if (prev == -1 || nums[curr] > nums[prev]) { // if prev is -1 or curr element is bigger
        // Remember we are saying prev==-1 because we have just mapped value of prev by incrementing, but prev is still -1
        take = 1 + helper(nums, curr + 1, curr);
    }
    int skip = helper(nums, curr + 1, prev); // if skipped curr will move further
    return dp[curr][prev + 1] = max(take, skip); // store values in dp and return also
}

int lengthOfLIS(vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
    return helper(nums, 0, -1);
}

int main() {
    // Input the array from the terminal
    cout << "Enter the numbers in the array separated by spaces: ";
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    cout << lengthOfLIS(arr) << endl;

    return 0;
}