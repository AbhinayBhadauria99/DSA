#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double ts = 0;
        
        for(int num : nums) {
            ts += num;
            pq.push(num);
        }

        double current = ts / 2;
        int count = 0;

        while(ts > current) {
            double el = pq.top();
            pq.pop();
            ts -= (el / 2);
            pq.push(el / 2);
            count++;
        }
        return count;
    }
};

int main() {
    cout << "Enter array elements (space-separated): ";
    vector<int> nums;
    int num;

    // Taking space-separated input till end of line
    string line;
    getline(cin, line);
    stringstream ss(line);
    
    while (ss >> num) {
        nums.push_back(num);
    }

    Solution sol;
    int result = sol.halveArray(nums);
    
    cout << "Minimum operations to halve array sum: " << result << endl;
    
    return 0;
}
