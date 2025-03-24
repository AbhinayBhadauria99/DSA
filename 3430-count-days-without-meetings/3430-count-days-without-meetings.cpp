class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int res=0;
        int end=0;
        sort(meetings.begin(),meetings.end());
        for(auto it: meetings){
           if(it[0]>end){
            res+=it[0]-end-1;  //reducing first previous elements second element wit current 1st ele.
           }  
           end=max(end,it[1]);  //keep updating second value in each iteration
        }
        if(days>end){  //for edge cases having merged meetings and at last they are having free time
            res+=days-end;
        }
        return res;
    }
};


