#include <bits/stdc++.h>
using namespace std;

class solution{
    private:
     int recursion(vector<int>& nums,int start,int end){  //remember start,end doesn't mean firstindex,lastindex
       if(start>=end) return 0;
       int steal=nums[start]+recursion(nums,start+2,end);
       int skip=recursion(nums,start+1,end);
       return max(steal,skip);
     };     
     int memoization(vector<int>& nums,int start,int end,vector<int> dp){
       if(start>=end) return 0;
       if(dp[start]!=-1) return dp[start];
       int steal=nums[start]+memoization(nums,start+2,end,dp);
       int skip=memoization(nums,start+1,end,dp);
       return dp[start]=max(steal,skip);
     };  
     int tabulation(vector<int>& nums, int start, int end) {  
        if (end - start == 1) return nums[start]; // Handle case where 'range' has only one element like [0,0],[5] etc means if nums have 1 or 2 elements
        vector<int> dp2(end - start);  //defining a seperate dp2 here because it should have size same as nums. because we are doing dp2.back() at last
        //if staticly mentioned 101 as size then it will return -1 if nums is shorter than 101
        dp2[0] = nums[start];
        dp2[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < end - start; i++) {
            dp2[i] = max(dp2[i - 1], nums[start + i] + dp2[i - 2]);
        }
        return dp2.back();
    };
     int so(vector<int>& nums, int start, int end) {  
        if (end - start == 1) return nums[start]; 
        int curr;
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 2; i < end - start; i++) {
            curr = max(prev1, nums[start + i] + prev2);
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    };


    public:   
     int houserrobber2(vector<int>& houses){
        if (houses.size() == 1) return houses[0];
       vector<int> dp(101,-1);      //no need of memset if dp is initialized in this way  dp(size_of_dp,value_of_each_index)
       //int res=max(memoization(houses,0,houses.size()-1,dp),memoization(houses,1,houses.size(),dp));
       //int res=max(tabulation(houses,0,houses.size()-1),tabulation(houses,1,houses.size()));
       int res=max(so(houses,0,houses.size()-1),so(houses,1,houses.size()));
       return res;
     };

};
int main(){
    vector<int> houses;

    cout << "Enter space-separated house money ";
    string input;
    getline(cin, input); // Read the entire input line
    stringstream ss(input); // Parse the input
    int num;
    while (ss >> num) {
        houses.push_back(num); // Add numbers to the vector
    }

    solution s;
    cout<<s.houserrobber2(houses)<<endl;
    return 0;
}