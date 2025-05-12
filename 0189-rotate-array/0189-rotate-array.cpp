class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp(n);  //its important to define size of temp
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=nums[i]; //agar same array me update karenge to array manipulate ho jayegi
        }
        nums=temp;
    }
};