#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates for i

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicates for j

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    // Convert one operand to long long to avoid integer overflow
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});

                        k++;
                        while (k < l && nums[k] == nums[k - 1]) k++;  // skip duplicates for k

                        l--;
                        while (k < l && nums[l] == nums[l + 1]) l--;  // skip duplicates for l
                    } 
                    else if (sum < target) {
                        k++;
                    } 
                    else {
                        l--;
                    }
                }
            }
        }

        return res;
    }
};

// Optional: a main function for testing
int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << ":\n";
    for (auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
