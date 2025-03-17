class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > pq; 
        for(auto it: nums){
            pq.push(it);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=pq.top();
            pq.pop();
        }
        return nums;
    }
};