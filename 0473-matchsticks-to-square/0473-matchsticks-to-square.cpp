class Solution {
public:
    bool helper(int idx,int target,vector<int>& matchsticks,vector<int>& box){
        if(idx==matchsticks.size()) {
            if(box[0]==box[1] && box[1]==box[2] && box[2]==box[3]){
                 return true;
            }
            return false;
        }
        
        for(int i=0;i<4;i++){
            if(box[i]+matchsticks[idx]>target) continue;
            box[i]+=matchsticks[idx];
            if(helper(idx+1,target,matchsticks,box)) return true;;
            box[i]-=matchsticks[idx];
            if (box[i] == 0) break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int> box(4,0);
        if(matchsticks.size()<=3) return false;
        int sum=0;
        for(auto it: matchsticks){
            sum+=it;
        }
        if (sum % 4 != 0) return false;
        int target=sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend()); //Agar solution possible nahi hai to jaldi fail ho jaoge (pruning)
        return  helper(0,target,matchsticks,box);
        
    }
};