class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals)); //on the basis of start point       
        vector<vector<int>> result;
        result.push_back(intervals[0]); //put first element

        for(int i = 1; i<intervals.size(); i++) {
            //keep putting values of coord. in below 2 variables in every iteration
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            //if  overlap
            if(curr_start <= result.back()[1]) { //check from already entered element in result
                result.back()[1] = max(result.back()[1], curr_end);
            } else {
                //there is no overlap
                result.push_back(intervals[i]);
            }

        }

        return result;

    }
};