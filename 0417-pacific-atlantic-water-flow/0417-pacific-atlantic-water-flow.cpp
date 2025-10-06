class Solution {
public:
    void mark(int i,int j,vector<vector<bool>>& ocean,int oi,int oj,vector<vector<int>>& heights){

   if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || ocean[i][j] || (oi>=0 && oj>=0 && heights[oi][oj]>heights[i][j])) return;

   ocean[i][j]=true;
   mark(i+1,j,ocean,i,j,heights);
   mark(i,j+1,ocean,i,j,heights);
   mark(i-1,j,ocean,i,j,heights);
   mark(i,j-1,ocean,i,j,heights);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r= heights.size();
        int c= heights[0].size();
        vector<vector<int>> res;

        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        for(int i=0;i<r;i++){
            mark(i,0,pacific,-1,-1,heights);
            mark(i,c-1,atlantic,-1,-1,heights);
        }
        for(int j=0;j<c;j++){
            mark(0,j,pacific,-1,-1,heights);
            mark(r-1,j,atlantic,-1,-1,heights);
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};