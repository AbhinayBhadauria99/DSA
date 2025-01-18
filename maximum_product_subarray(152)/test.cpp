#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int bruteforce(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            for (int j = i + 1; j < n; j++) {
                curr *= nums[j];
                res = max(res, curr);
            }
        }
        return res;
    }

    int recursion(vector<int>& nums, int index, int tempmax, int tempmin, int globalmax) {
        if (index == nums.size()) return globalmax;

        int num = nums[index];
        int temp = tempmax; // Preserve current tempmax before updating it

        tempmax = max(num, max(tempmax * num, tempmin * num));
        tempmin = min(num, min(temp * num, tempmin * num));
        globalmax = max(globalmax, tempmax);

        return recursion(nums, index + 1, tempmax, tempmin, globalmax);
    }

public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int globalmax = INT_MIN;
        return recursion(nums, 0, 1, 1, globalmax);
    }
};

int main() {
    // Input the array from the terminal
    cout << "Enter the numbers in the array separated by spaces: ";
    string input;
    getline(cin, input);
    stringstream ss(input);

    vector<int> nums;
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    // Create an instance of the Solution class and call the maxProduct method
    Solution solution;
    int result = solution.maxProduct(nums);

    // Output the result
    cout << "The maximum product subarray is: " << result << endl;

    return 0;
}
