class Solution {
public:
    vector<vector<int>> res;
    void helper(int start,vector<int>& temp,int n,int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            helper(i+1,temp,n,k);
            temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        helper(1,temp,n,k);
        return res;     
        
    }
};

