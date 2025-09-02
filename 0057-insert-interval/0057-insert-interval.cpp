class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int first=newInterval[0];
        int second=newInterval[1];
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size()){
            int temp1=intervals[i][0];
            int temp2=intervals[i][1];
            if(first>temp2){//interval aage hai abhi range me nahi
                ans.push_back({temp1,temp2});
                i++;
            }
            else if(temp1>second){ //intreval peeche reh gya ab tak merge ho chuka hoga
                break; //yaha se break kar do loop ko
            }
            else{ //merge karte raho interval ko
                first=min(first,temp1);
                second=max(second,temp2);
                i++;
            }
        }
        ans.push_back({first,second});  //interval daal do
        while(i<intervals.size()){ //break kiya tha to ab interval ke baad baaki bache hue daal do
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return ans;
    }
};