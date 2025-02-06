#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLength = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];  
            while (sum >= target) {  
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];  
                left++;  
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

int main() {
    int target, n;
    cout << "Enter target: ";
    cin >> target;

    cin.ignore();  // Ignore leftover newline character

    cout << "Enter elements of array (space-separated): ";
    string line;
    getline(cin, line);

    vector<int> nums;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }


    Solution sol;
    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum Subarray Length: " << result << endl;

    return 0;
}
