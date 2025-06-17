class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { //if overlapping then merge coordinates
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;

        result.push_back(intervals[0]); //put first element of interval in result vector
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < result.back()[1]) { //if overlapping
            //overlapping ke case me result me pade coordinates ko update kare
                result.back()[0] = max(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else { //non overlapping
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //vector for x-axis
        vector<vector<int>> hor;    
        //vector for y-aixs
        vector<vector<int>> vert;

        for(auto &coord : rectangles) {
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];
           // putting coordinates in hor. and vert. vector
            hor.push_back({x1, x2});
            vert.push_back({y1, y2});
        }
      //put the merged hor and vert vectors in res1 and res2 
        vector<vector<int>> result1 = merge(hor);
        vector<vector<int>> result2 = merge(vert);

        return result1.size() >= 3 || result2.size() >= 3;
    }
};

