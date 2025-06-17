class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int count=0;
        vector<int> res;
        int m= grid.size();
        int n= grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res.push_back(grid[i][j]);
            }
        }
        sort(res.begin(),res.end());
        int median=res[res.size()/2]; //we have to use median as its better choice than average
        for(int i=0;i<res.size();i++){
            if(abs(res[i]-median)%x!=0){
                return -1;
            }
            count+=abs(res[i]-median)/x;
        }
        return count;
    }
};